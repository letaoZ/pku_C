#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n=0;
    cin>> n;

    int res = -1;
    int score = -1;
    for(int i=0;i<n;++i){
        cin >> score;
        if(score>res)

            res = score;
    }
    cout<<res<<endl;

    return 0;
}