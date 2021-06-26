/*编程题＃5：走出迷宫
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
当你站在一个迷宫里的时候，往往会被错综复杂的道路弄得失去方向感，如果你能得到迷宫地图，事情就会变得非常简单。 

假设你已经得到了一个n*m的迷宫的图纸，请你找出从起点到出口的最短路。

输入
第一行是两个整数n和m(1 <= n,m <= 100)，表示迷宫的行数和列数。

接下来n行，每行一个长为m的字符串，表示整个迷宫的布局。字符'.'表示空地，'#'表示墙，'S'表示起点,'T'表示出口。

输出
输出从起点到出口最少需要走的步数。(你不能起出迷宫外)

样例输入
3 3
S#T
.#.
...

output
6

*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int m,n;
    cin>>m>>n;

    vector<vector<char>> g(m,vector<char>(n,'#'));
    pair<int, int> s;

    for(int i = 0; i<m; ++i){
        for( int j = 0; j<n ; ++j){
            cin>>g[i][j];
            if (g[i][j] == 'S')
                s = make_pair(i,j);

        }
    }

    vector< vector<int>> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };

    queue<pair<int,int>> q;
    q.push(s);
    int cnt = 0;
    while (!q.empty()){
        int L = q.size();

        for(int k=0; k<L; ++k){
            pair<int, int> p = q.front();
            q.pop();
            for(auto d:dir){
                int x = p.first + d[0];
                int y = p.second+d[1];
                if (x<0 || y<0 || x>=m || y>=n)
                    continue;
                if (g[x][y] == '#')
                    continue;
                if (g[x][y] == 'T'){
                    cout<<cnt + 1<<endl;
                    return 0;
                }
                q.push(make_pair(x,y));
                g[x][y] = '#';

            }
        

        }
        cnt += 1;
        
    }
    cout<<-1<<endl;


    return 0;
}