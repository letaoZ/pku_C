#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<vector<int> > mat;

    //matrix of each person's opinion
    mat.push_back(vector<int> {0,1,0,0});
    mat.push_back(vector<int> {0,0,0,1});
    mat.push_back(vector<int> {1,1,0,1});
    mat.push_back(vector<int> {1,1,1,0});

    vector<int> ss(4);
    for(auto v:mat)
        for(int i=0;i<4; ++i)
            ss[i] += v[i];

    // only one person is correct
    // so summation vector ss only has one value 1
    int car = -1;
    for(int i=0;i<4; ++i){
        if( ss[i] == 1){
            car = i+1;
            break;
        }
    }
    int person = -1;
    for(int p=0;p<4; ++p){
        vector<int> v = mat[p];
        for(int i=0;i<4; ++i){
            if(v[i] == 1){
                person = 'A' + i;
                break;
            }
        }
        if(person>=0)
            break;
    }
    char p = person;

    cout<<car<<endl;
    cout<<p<<endl;
    return 0;
}