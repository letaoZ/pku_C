#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n = -1;
    cin >> n;
    if (n==0){
        cout<<n<<endl;
        return 0;
    }
    n = abs(n);
    vector<int> res;
    while(n>0){
        int dig = n%10;
        res.push_back(dig);
        n /= 10;
        n = int(n);
    }

    vector<int>::reverse_iterator it = res.rbegin();
    while (it != res.rend()){
        cout<<*it<<endl;
        it += 1;
    }
    return 0;
}