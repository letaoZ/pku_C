
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> age(N);
    for(int i=0; i<N; ++i)
        cin>>age[i];

    vector<double>cnt(4);

    for(auto it:age){
        if(it<=18)
            cnt[0] += 1./N;
        else if(it <= 35)
            cnt[1] += 1./N;
        else if(it <= 60)
            cnt[2] += 1./N;
        else
            cnt[3] += 1./N;
    }
    // vector of string, definition
    const vector<string> bucket{"1-18: ","19-35: ","36-60: ","60-: "};

    for(int i=0;i<4;++i){
        cout<<fixed<<bucket[i]<<setprecision(2)<<cnt[i]*100<<"%"<<endl;
    }

    return 0;
}