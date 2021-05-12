#include <iostream>
using namespace std;

int BOUND = 10000;

int main(){
    int n=0;
    int nums[BOUND];
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> nums[i];
    }
    ## my solution
    int piv = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i+1;j<n; ++j) {
            if( nums[i]>nums[j]) {
                piv = nums[i];
                nums[i]=nums[j];
                nums[j] = piv;
            }
        }
    }

    for(int i=0; i<n ; ++i)
        cout<<nums[i]<<endl;
    return 0;


}