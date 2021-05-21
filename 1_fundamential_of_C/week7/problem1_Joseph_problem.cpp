#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void myFunction(vector<pair<int,int>> data){
        /* iterate of vector of pairs
    equivalent to pointer, must use ->first
    for(vector< pair<int,int>>::iterator it=data.begin(); it!=data.end(); it++)

    pair, use dot .fist
    for(auto it:data){
        cout<<it.first<<endl;
    }
    */
    for(auto it = data.begin(); it!=data.end(); it ++){
        int n = it->first;
        int m = it->second;
        int N = n;
        vector<int> arr(n);
        for(int i=0; i<n; ++i)
            arr[i]=i+1;
        int idx = 0;
        int cnt = 1;
        while(n>1){
            cout<<"index "<<idx + 1<<" cnt: "<<cnt<<endl;

            if(arr[idx]!=0){
                if(cnt == m){
                    arr[idx] = 0;
                    n -= 1;
                    cnt = 1;
                }
                else{
                    cnt += 1;
                }

            }
            idx += 1;
            idx %= N;


        }
        for(idx=0;idx<N;++idx){
            if(arr[idx] != 0 )
                cout<<idx + 1<<"done"<< endl;
        }


    }
}

int main(){
    int N = 0;

    int enda=-1, endb = -1;

    vector<pair<int,int> > data;

    while(true){
        cin>>enda;
        cin>>endb;
        // cout<<enda<<endb<<endl;
        if(enda==0 && endb==0)
            break;
        data.push_back(make_pair(enda,endb));

    }
    cout<<"data done"<<endl;
    // myFunction(data);
    

    // keep track of each index's pre and after index
    for(auto it:data){
        int n = it.first;
        int m = it.second;
        vector<int> pre(n);
        vector<int> aft(n);
        for(int i =0; i<n; ++i){
            pre[i+1] = i;
            aft[i] = i+1;
        }
        int cur = 0;
        int res = -1;
        while(true){
            for(int cnt=0;cnt<m-1;++cnt)
                cur = aft[cur];
            cout<<"cur: "<<cur+1<<" numb: "<<"done"<<endl;

            int preCur = pre[cur];
            int aftCur = aft[cur];
            aft[preCur] = aftCur;
            pre[aftCur] = preCur;
            if (preCur == aftCur){
                res = preCur ;

                break;

            }
            cur = aftCur;

        }
        cout<<res +1<<endl;

            
    }


    return 0;
}