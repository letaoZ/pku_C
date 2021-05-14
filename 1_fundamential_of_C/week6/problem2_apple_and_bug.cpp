#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    // n apples
    int n=0;
    // every x hour eats an apple
    int x=0;
    // in y hour
    int y=0;

    cin>>n>>x>>y;

    int res = 0;
    if(n==0 || y==0){
        cout<<res<<endl;
        return 0;
    }
    if(x==0){
        cout<<n<<endl;
        return 0;
    }

    res = int(y/x);
    res = (n-res>0)?(n-res):0;
    cout<<res<<endl;
    return 0;
}