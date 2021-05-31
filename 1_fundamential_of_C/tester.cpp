#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void p(int []);

int main(){

    int a[] = {2,3};
    p(a);


    return 0;
}


void p(int a[]){
    cout<<"inside"<<endl;
    a[0] = 1000;
    cout<<a[0]<<endl;
}