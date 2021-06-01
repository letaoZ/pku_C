/*

Put M apples in N plates, pltes can be empty. Number of ways?

Note: eg. you have 7 apples, 3 plates, [1,5,1] and [1,1,5] are the same methods

f(n,m) = f(n,m-1) one empty plate 
        +f(n-m,m) all plates are Nonempty, put one apple in each plate. Then start as put n-m apples in m plates.


*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int insert(int n, int m){
    if (m==1)
        return 1;
    if (n==0)
        return 1;// assume zero apples, m plates = 1 method
        
    if (n>=m)
        return insert(n,m-1) + insert(n-m,m);
    else// if plates > apples, you must have at least m-n many empty plates. 
        return insert(n,n);
}



int insert_dp(int n, int m, vector< vector<int>>& dp){
    
    
    if (dp[n][m]>0)
        return dp[n][m];
    if (n>=m)
        return dp[n][m] = insert(n,m-1) + insert(n-m,m);
    else// if plates > apples, you must have at least m-n many empty plates. 
        return dp[n][m] = insert(n,n);
}

int main(){

    int n,m;
    n = 7;
    m = 3;
    // if plates > apples, you must have at least m-n many empty plates.
    if (m>n)
        m = n;
    cout<<insert(n,m)<<endl;

    vector< vector<int> > dp(n+1, vector<int>(m+1,0));
    for(auto &v:dp)
        v[1] = 1;
    for(int k=0;k<=m; ++k)
        dp[0][k] = 1;
    cout<<insert_dp(n,m,dp)<<endl;

    return 0;

}