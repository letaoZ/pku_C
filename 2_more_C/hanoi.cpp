#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/// assume you can move from the very left directly to the very right
int hanoi(int n){
    if (n==1)
        return 1;
    
    return 2*hanoi(n-1) + 1;
    

};
int main(){

    int n = 4;
    cout<<hanoi(n)<<endl;

    return 0;
}