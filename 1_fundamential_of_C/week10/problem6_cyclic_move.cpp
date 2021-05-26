/*


编程题＃6：循环移动
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
给定一组整数，要求利用数组把这组数保存起来，再利用实现对数组中的数循环移动。假定共有n个整数，则要使前面各数顺序向后移m个位置，并使最后m各数变为最前面的m各数。

注意，不要用先输出后m个数，再输出前n-m个数的方法实现，也不要用两个数组的方式实现。

要求只用一个数组的方式实现，一定要保证在输出结果时，输出的顺序和数组中数的顺序是一致的。

输入
输入有两行：第一行包含一个正整数n和一个正整数m，第二行包含n个正整数。每两个正整数中间用一个空格分开。

输出
输出有一行：经过循环移动后数组中整数的顺序依次输出，每两个整数之间用空格分隔。

样例输入

11 4
15 3 76 67 84 87 13 67 45 34 45


样例输出
67 45 34 45 15 3 76 67 84 87 13
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// to make actual changes! you need to take the ADDRESS!
void reverse_mat(vector<int>  & mat,int x, int y){
    if( x>=y || x<0 || y>= mat.size()){
        return; // must have ; after return!!!
    }

    reverse(mat.begin()+x, mat.begin()+y+1);
    // cout<<" in: "<<endl;
    // for(int i=0;i<mat.size();++i)
    //     cout<<setw(4)<<mat[i];
    // cout<<endl;
}

int main(){
    int N, M = 0;

    cin>>N>>M;
    M %= N;
    vector<int> mat(N,0);
    for(int i=0;i<N;++i)
        cin>>mat[i];


    // idea:
    // reverse the last M elts
    // reverse the first N-M elts
    // reverse the whole mat
    reverse_mat(mat, N-M,N-1);
    reverse_mat(mat, 0,N-M-1);
    reverse_mat(mat, 0,N-1);
    for(int i=0;i<N;++i)
        cout<<setw(4)<<mat[i];
    cout<<endl;

    return 0;
} // namespaces std;

