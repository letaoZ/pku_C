/*
编程题＃4：寻找平面上的极大点
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
在一个平面上，如果有两个点(x,y),(a,b),如果说(x,y)支配了(a,b)，这是指x>=a,y>=b;

用图形来看就是(a,b)坐落在以(x,y)为右上角的一个无限的区域内。

给定n个点的集合，一定存在若干个点，它们不会被集合中的任何一点所支配，这些点叫做极大值点。

编程找出所有的极大点，按照x坐标由小到大，输出极大点的坐标。

本题规定：n不超过100，并且不考虑点的坐标为负数的情况。

输入
输入包括两行，第一行是正整数n，表示是点数，第二行包含n个点的坐标，坐标值都是整数，坐标范围从0到100，输入数据中不存在坐标相同的点。

输出
按x轴坐标最小到大的顺序输出所有极大点。

输出格式为:(x1,y1),(x2,y2),...(xk,yk)

注意：输出的每个点之间有","分隔,最后一个点之后没有",",少输出和多输出都会被判错

样例输入
5
1 2 2 2 3 1 2 3 1 4

output
(1,4), (2,3), (3,1)
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int m;
    cin>>m;

    vector<pair<int,int>> mat;

    for(int i=0; i<m; ++i){
        int a,b;
        cin>>a>>b;
        mat.push_back(make_pair(a,b));
    }
    sort(mat.begin(),mat.end());

    vector<pair<int,int> > res;


    for(int i=0; i<m; ++i){
        pair<int,int> a = mat[i];
        int j = i+1;
        for(;j<m; ++j){
            if(mat[j].second >= a.second)
                break;
        }
        if (j==m)
            res.push_back(a);

    }
    for(auto v:res)
        cout<<'('<<v.first<<','<<setw(2)<<v.second<<"), ";

    return 0;
}