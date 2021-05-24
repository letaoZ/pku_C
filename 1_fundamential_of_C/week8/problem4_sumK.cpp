#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k = 0;

    cin>>n>>k;
    vector<int> nums(n);

    for(int i=0;i<n;++i)
        cin>>nums[i];

    sort(nums.begin(),nums.end());

    int l = 0;
    int r = n-1;
    cout<<k<<endl;
    while(l<r){
        int ss= nums[l] +nums[r];
        if(ss == k){
            cout<<"yes"<<endl;
            return 0;
        }
        else if (ss < k){
            l += 1;
        }
        else{
            r -= 1;
        }
    }   
    cout<<"no"<<endl;
    return 0;
}