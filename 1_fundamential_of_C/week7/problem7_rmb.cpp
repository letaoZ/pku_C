#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int total = 0;
    cin>>total;

    const vector<int> value{100,50,20,10,5,1};
    vector< int > res(value.size());
    int r = total;
    for(int i=0; i<value.size(); ++i){
        int myVal = value[i];
        res[i] = int(r/myVal);
        r = r%myVal;
        cout<<res[i]<<endl;
    }

    return 0;
}