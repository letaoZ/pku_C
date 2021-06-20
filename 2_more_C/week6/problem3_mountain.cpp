/*
编程题＃3：寻找山顶
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
在一个m×n的山地上，已知每个地块的平均高程，请求出所有山顶所在的地块（所谓山顶，就是其地块平均高程不比其上下左右相邻的四个地块每个地块的平均高程小的地方)。

输入
第一行是两个整数，表示山地的长m（5≤m≤20）和宽n（5≤n≤20）。

其后m行为一个m×n的整数矩阵，表示每个地块的平均高程。每行的整数间用一个空格分隔。

输出
输出所有上顶所在地块的位置。每行一个。按先m值从小到大，再n值从小到大的顺序输出。

样例输入
10 5
0 76 81 34 66
1 13 58 4 40
5 24 17 6 65
13 13 76 3 20
8 36 12 60 37
42 53 87 10 65
42 25 47 41 33
71 69 94 24 12
92 11 71 3 82
91 90 20 95 44

output
0 2
0 4
2 1
2 4
3 0
3 2
4 3
5 2
5 4
7 2
8 0
8 4
9 3
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> brutal(vector<vector<int>> mat,int m, int n ){
    vector< vector<int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };
    vector<pair<int, int>> res;
    for(int i=0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            int val = mat[i][j];
            bool flag = true;
            for(auto d:dir){
                int x = i + d[0];
                int y = j + d[1];
                if (x>=m || x<0 || y>=n || y<0)
                    continue;
                    
                if (mat[x][y]>val){
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(make_pair(i,j));

        }
    }
    return res;


}

void dfs(
    vector<vector<int>> mat, int m, int n,
    int i, int j, 
    vector<vector<int>> &visited,
    vector<pair<int, int>> &res){

    vector< vector<int>> dir = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };


    for(int i=0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            if (visited[i][j])
                continue;
            visited[i][j] = 1;
            bool flag = true;
            int val = mat[i][j];
            for(auto d:dir){
                int x = i + d[0];
                int y = j + d[1];
                if (x>=m || x<0 || y>=n || y<0)
                    continue;
                    
                if (mat[x][y]>val){
                    flag = false;
                    dfs(mat,m,n,i,j,visited,res);
                    break;
                }
            }

            if (flag){
                res.push_back(make_pair(i,j));
                for(auto d:dir){
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x>=m || x<0 || y>=n || y<0)
                        continue;
                    if (mat[x][y]<val)
                        visited[x][y] = 1;
                }
            }
            
        }
    }

}

int main(){
    int m,n = 0;
    cin>>m>>n;
    vector<vector<int>> mat(m, vector<int> (n,0) );
    vector<vector<int>> visited(m, vector<int> (n,0) );

    for(int i=0; i<m; ++i){
        for(int j = 0; j<n; ++j){
            cin>>mat[i][j];
        }
    }
    vector< pair<int, int>> res,res1;

    res = brutal(mat,m,n);
    for(int i=0; i<m; ++i)
        for(int j = 0; j<n; ++j)
            dfs(mat,m,n,i,j,visited,res1);
    

    for(auto v:res1)
        cout<<v.first<<setw(2)<<v.second<<endl;


    return 0;

}
