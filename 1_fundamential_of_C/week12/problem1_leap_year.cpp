/*
编程题＃1：判断闰年
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
判断某年是否是闰年。

输入
输入只有一行，包含一个整数a(0 < a < 3000)

输出
一行，如果公元a年是闰年输出Y，否则输出N

样例输入
2006

样例输出
N


*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int year = 0;
    cin >> year;

    char res = 'Y';
    if(year%4 == 0){
        if(year%100 == 0){
            if(year%400 != 0)
                res = 'N';
        }

    }
    else
        res = 'N';

    cout<<res<<endl;

    return 0;
}