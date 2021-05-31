/*
编程题＃4：Tomorrow never knows？
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。

读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。

输入
输入仅一行，格式为yyyy-mm-dd的日期。

输出
输出也仅一行，格式为yyyy-mm-dd的日期

样例输入
2010-07-05

样例输chu
2010-07-06
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int MAX_LEN = 256;

bool leapyear(int yyyy){

    return (yyyy%4==0&&yyyy%400!=0 || yyyy%400==0);

}

string data_convert(int y, int m, int d){
    string sy = to_string(y);
    string sm = to_string(m);
    string sd = to_string(d);
    // cout<<sy<<sm<<sd<<endl;
    if(sm.length() == 1)
        sm = "0"+sm;
    if(sd.length() == 1)
        sd = "0"+sd;
    // cout<<sm<<(sm.length())<<endl;
    return (sy + "-" + sm + "-" + sd);
}

int main(){
    char a[MAX_LEN];
    char b[MAX_LEN];
    char c[MAX_LEN];

    int months[12] = {30};
    vector<int> month31 = {1,3,5,7,8,10,12};
    for(auto ii:month31)
        months[ii-1] = 31;
    months[1] = 28;


    cin.getline(a,MAX_LEN,'-');
    cin.getline(b,MAX_LEN,'-');
    cin.getline(c,MAX_LEN);
    
    int y = atoi(a);
    int m = atoi(b);
    int d = atoi(c);
    // cout<<a<<y<<endl;
    // cout<<b<<m<<endl;
    // cout<<c<<d<<endl;
    
    if(leapyear(y))
        months[1] = 29;
    int ny = y;
    int nd = d;
    int nm = m;
        


    // last day of the month
    if(months[m-1]==d){
        nd = 1;
        nm = m%12 + 1;
        if(nm==1)
            ny = y+1;
    }
    else{
        nd += 1;
    }
    cout<<data_convert(ny,nm,nd)<<endl;

    return 0;
};
