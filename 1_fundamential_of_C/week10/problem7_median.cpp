/*
编程题＃7：中位数
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 2000ms 内存限制: 65536kB

描述
中位数定义：一组数据按从小到大的顺序依次排列，处在中间位置的一个数或最中间两个数据的平均值（如果这组数的个数为奇数，则中位数为位于中间位置的那个数；如果这组数的个数为偶数，则中位数是位于中间位置的两个数的平均值）.

给出一组无序整数，求出中位数，如果求最中间两个数的平均数，向下取整即可（不需要使用浮点数）

输入
该程序包含多组测试数据，每一组测试数据的第一行为N，代表该组测试数据包含的数据个数，1 <= N <= 15000.

接着N行为N个数据的输入，N=0时结束输入

输出
输出中位数，每一组测试数据输出一行

样例输入
4
10
30
20
40
3
40
30
50
4
1
2
3
4
0

样例输出
25
40
2

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){


    int N = -1;
    vector<int> res;
    while(true){
        cin>>N;
        if (N == 0) break; 
        vector<int> mat(N,0);
        for(int i=0;i<N;++i)
            cin>>mat[i];
        sort(mat.begin(), mat.end());
        int m0 = (mat.size()-1)/2;
        int m1 = (mat.size())/2;
        int resi = (mat[m0]+mat[m1])/2;
        res.push_back(resi);
    }
    for(auto a:res)
        cout<<a<<endl;

    return 0;
}