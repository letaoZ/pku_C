/*
编程题＃4：矩阵交换行
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
在main函数中， 生成一个5*5的矩阵，输入矩阵数据，并输入n，m的值。判断n，m是否在数组范围内，如果不在，则输出error；如果在范围内，则将n行和m行交换，输出交换n，m后的新矩阵。

输入
5*5矩阵的数据，以及n和m的值。

输出
如果不可交换，则输出error

如果可交换，则输出新矩阵

样例输入
第一组
1 2 2 1 2
5 6 7 8 3
9 3 0 5 3
7 2 1 4 6
3 0 8 2 4
0 4
第二组
1 2 2 1 2
5 6 7 8 3
9 3 0 5 3
7 2 1 4 6
3 0 8 2 4
5 1

第一组
   3   0   8   2   4
   5   6   7   8   3
   9   3   0   5   3
   7   2   1   4   6
   1   2   2   1   2
第二组
error
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N = 5;
int main(){

    int mat[N][N] = {0};
    for(int i=0; i<N; ++i)
        for(int j=0;j<N; ++j)
            cin>>mat[i][j];
    int m,n = 0;
    cin>>m>>n;
    if(m>=N or n>=N or m<0 or n<0){
        cout<<"error"<<endl;
        return 0;
    }

    for(int i=0;i<N; ++i){
        int tmp = mat[m][i];
        mat[m][i] = mat[n][i];
        mat[n][i] = tmp;
    }
    // pay attention to {}
    // if the first for loop has output cout<<endl
    // you MUST have a pair of {}
    for(int i=0; i<N; ++i){
        for(int j=0;j<N; ++j)
            cout<<setw(4)<<mat[i][j];
        
        cout<<endl;
    }

    return 0;
}

