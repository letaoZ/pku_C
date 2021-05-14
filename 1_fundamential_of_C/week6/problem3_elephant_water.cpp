#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    //h and r
    int h = 0;
    int r = 0;

    cin>>h>>r;

    const double pi = atan(1)*4;

    double vol = pi*r*r*h;

    if(vol == 0){
        cout<<"error input"<<endl;
        return 0;
    }

    int res = int( (1000*20.)/vol );
    if(res*vol<1000*20){
        res += 1;
    }
    cout<<res<<endl;
    
    return 0;
}