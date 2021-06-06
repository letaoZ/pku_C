#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sum1(int * ,int  , int  );
void sum2(int (*)[3],int  , int  );
void sum3(int [][3],int  , int  );


int * getValp(){
    static int v1 = 12;
    return &v1;
}

int * getValq(){
    static int v1 = 22;
    return &v1;
}

void static_test(){
    int a = 0;
    static int b = 0;
    a += 1;
    b += 1;

    cout<<"a:"<<a<<endl;
    cout<<"b:"<<b<<endl;

}


int main(){
    int a[][3]{
        {1,2,3},
        {4,5,6}
    };
    sum1(*a,2,1);
    sum2(a,2,1);
    sum3(a,2,1);

    int *p, *q;
    p = getValp();
    q = getValq();
    cout<<"p"<<*p<<endl;
    cout<<"q"<<*q<<endl;
    
    cout<<"p"<<*p<<endl;
    cout<<"q"<<*q<<endl;
    
    for(int i=0;i<3;++i){
        cout<<"static_test call "<<i<<endl;
        static_test();
        }
    return 0;
}


void sum1(int * x,int m, int n){
    cout<<(*(x+(m-1)*3 + n-1) ) <<endl;

}

void sum2(int (*x)[3],int m, int n){
    cout<<*(*(x+m-1) + n-1) <<endl;

}

void sum3(int x[][3],int m, int n){
    cout<<*(*(x+m-1) + n-1) <<endl;

}

