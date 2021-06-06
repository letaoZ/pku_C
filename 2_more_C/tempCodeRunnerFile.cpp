#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sum1(int * x,int m, int n){
    cout<<(*(x+m-1) + n-1) <<endl;

};

int main(){
    int a[][3]{
        {1,2,3},
        {4,5,6}
    };
    sum1(*a,2,1);
    return 0;
}