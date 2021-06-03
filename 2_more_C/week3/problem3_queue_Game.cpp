/*
编程题＃3：排队游戏
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
在幼儿园中，老师安排小朋友做一个排队的游戏。首先老师精心的把数目相同的小男孩和小女孩编排在一个队列中，每个小孩按其在队列中的位置发给一个编号（编 号从0开始）。然后老师告诉小朋友们，站在前边的小男孩可以和他后边相邻的小女孩手拉手离开队列，剩余的小朋友重新站拢，再按前后相邻的小男孩小女孩手拉 手离开队列游戏，如此往复。由于教师精心的安排，恰好可以保证每两个小朋友都能手拉手离开队列，并且最后离开的两个小朋友是编号最小的和最大的两个小朋 友。（注：只有小男孩在前，小女孩在后，且他们两之间没有其他的小朋友，他们才能手拉手离开队列）。请根据老师的排队，按小女孩编号从小到大的顺序，给出 所有手拉手离开队列的小男孩和小女孩的编号对。

输入
用一个字符串代表小朋友队列。字符串中只会出现两个字符（样例输入里用的是 括号但实际数据则不一定），分别代表小男孩和小女孩，首先出现的字符代表小男孩，另一个字符代表小女孩。小孩总数不超过100

输出
按小女孩编号顺序，顺序输出手拉手离开队列的小男孩和小女孩的编号对，每行一对编号，编号之间用一个空格分隔。


inputs:
((()(())())(()))

outputs:
2 3
5 6
4 7
8 9
1 10
12 13
11 14
0 15
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    stack<int> st;

    char ss[200];

    vector<pair<int,int> > res;
    cin.getline(ss,200,'\n');

    char *p = ss;
    int girl = -1;
    int boy = -1;

    while(*p){
        if(*p == '('){
            p++;
            girl ++;
            boy ++;
            st.push(girl);
            continue;
        }
        boy ++;
        res.push_back(make_pair(st.top(),boy) );
        st.pop();
        girl = boy;
        p++;


    }
    for(auto v:res)
        cout<<v.first<<' '<<v.second<<endl;

    return 0;
}