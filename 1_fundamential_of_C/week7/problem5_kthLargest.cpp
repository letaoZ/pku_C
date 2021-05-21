#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
    return nums[k - 1];
}

int main(){
    // get number of inputs
    // get find the Kth largest
    int N =0, K=0;
    cin>>N>>K;

    vector<int> nums(N);
    for(int i=0; i<N; ++i)
        cin>>nums[i];

    int res = findKthLargest(nums, K);
    cout<<res<<endl;
    return 0;
}