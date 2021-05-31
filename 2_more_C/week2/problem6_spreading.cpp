/*
编程题＃6：流感传染
注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。

输入
第一行一个数字n，n不超过100，表示有n*n的宿舍房间。

接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。

接下来的一行是一个整数m，m不超过100.

输出
输出第m天，得流感的人数

样例输入
5
....#
.#.@.
.#@..
#....
.....
4


output 
16
*/
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n = 5;
    int m = 4;
    vector< vector<char> > a(n, vector<char>(n,' ') );
    a = {
        {'.','.','.','.','#'},
        {'.','#','.','@','.'},
        {'.','#','@','.','.'},
        {'#','.','.','.','.'},
        {'.','.','.','.','.'}
    };

    int cnt = 0;

    queue< pair<int,int> > q;
    for(int i=0; i< n; ++i){
        for(int j=0; j<n; ++j){
            if(a[i][j] == '@'){
                // q.emplace(i,j);
                q.push(make_pair(i,j));
                cnt += 1;
            }
        }
    }
    
    // bfs, queue
    vector<vector<int> > dir{
        {1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> visited(n, vector<int> (n,0));

    for(int i =0; i<m-1;++i){
        int L = q.size();
        // cout<<"cnt"<<cnt<<endl;
        for(int k=0;k<L;++k){
            pair<int,int> tmp = q.front();
            q.pop();
            for(auto dd:dir){
                int x = dd[0] + tmp.first;
                int y = dd[1] + tmp.second;
                if(x>=n or y>=n or x<0 or y<0)
                    continue;
                if(visited[x][y]>0)
                    continue;
                if(a[x][y]!='.')
                    continue;
                a[x][y] = '@';
                visited[x][y] = 1;
                cnt += 1;
                q.emplace(x,y);
            };
            // cout<<tmp.first<<tmp.second<<endl;
        };
    };

    std::cout<<cnt<<endl;

    return 0;
}