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
    // my solution
    // sort and switch when:
    // left > right or left and right share the same oddity
    int piv = 0;
    for(int i=0; i<n; ++i) {
        for(int j=1;j<n-i; ++j) {
            bool leftIsEven = nums[j-1]%2 == 0;
            bool rightIsEven = nums[j]%2 == 0;


            if( (nums[j]<nums[j-1] && leftIsEven==rightIsEven) || 
                (nums[j]%2 > nums[j-1]%2)  // odd is on the left of even
            ) {
                piv = nums[j-1];
                nums[j-1]=nums[j];
                nums[j] = piv;
            }
        }

    }

    for(int i=0; i<n ; ++i)
        cout<<nums[i]<<endl;



    return 0;


}