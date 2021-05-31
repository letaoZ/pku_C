/*
编程题＃2：四大湖
注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
我国有4大淡水湖。

A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。

B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。

C说：洪泽湖最小，洞庭湖第三。

D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。

已知这4个湖的大小均不相等，4个人每人仅答对一个，

请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。

输入
无。

输出
输出为4行，第1行为鄱阳湖的大小名次，从大到小名次分别表示为1、2、3、4；第2、3、4行分别为洞庭湖、太湖、洪泽湖的大小名次。

样例输入
(无)

样例输出
3(样例输出仅供格式参考，此题只有一个解， 。)
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    //洪泽湖，洞庭湖，鄱阳湖，太湖。
    int ranking[][4] = {
        {4,1,3,2},
        {1,4,2,3},
        {4,3,0,0},
        {2,3,1,4},
        // 1 3 4 2
    };
    // since everyone is only right once, person C can be correct on 鄱阳湖，太湖; NOT on 洪泽湖，洞庭湖，
    // just try each ranking combination
    vector<int> a{1,2,3,4};
    do{
        int flag = 0;
        for(int i=0;i<4;++i){
            int cnt = 0;
            if(i!=2){
                for(int j=0;j<4;++j){
                    if(a[j]==ranking[i][j])
                        cnt += 1;
                }
                if(cnt != 1)
                    break;
                flag += 1;
            }
            else{
                for(int j=0;j<2;++j){
                    if(a[j]==ranking[i][j])
                        cnt += 1;
                }
                // int cnt0 = cnt;
                // cnt += ((a[2]==1) + (a[3]==2));
                // cnt0 += ((a[2]==2) + (a[3]==1));
                if(cnt==1)// && cnt0==1)
                    flag += 1;
                else
                    break;

            }
        }
        if(flag == 4){
            for(int i=0;i<4;++i)
                cout<<setw(4)<<a[i];
            cout<<endl;
            // return 0;
        }
    }while(next_permutation(a.begin(), a.end()));


    return 0;
}