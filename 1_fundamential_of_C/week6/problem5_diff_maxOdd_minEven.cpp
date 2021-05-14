#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n=0;
    cin>>n;

    // input number
    int num;
    int even= INT_MAX;
    int odd = -1;

    for(int i=0;i<n; ++i){
        cin>>num;
        if(num%2==0)
            even = min(even, num);
        else
            odd = max(odd,num);
            
    }
    cout<<odd-even<<endl;

    return 0;
}