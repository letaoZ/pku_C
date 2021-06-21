/*编程题＃2：字符串中次数第2多的字母
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
输入一串长度不超过500个符号的字符串，
输出在串中出现第2多的英语字母(大小写字母认为相同)和次数
（如果串中有其它符号，则忽略不考虑）。
如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。 

例 ab&dcAab&c9defgb 

这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为 

D+d:2 

(假定在字符串中，次数第2多的字母总存在)

输入
一个字符串

输出
大写字母+小写字母:个数

样例输入

ab&dcAab&c9defgb
样例输出
D+d:2
*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    char arr[500];
    cin.getline(arr,500);

    vector<int> visited('z'+1,0);
    int m1, m2=0;
    int c1, c2 = arr[0];
    for(int i=0; arr[i]!='\0'; ++i){
        int a = arr[i];
        cout<<arr[i]<<endl;
        if ( (a>='a' && a<='z') || (a>='A' && a<='Z')){
            if (a>='a' && a<='z')
                a = a- ('a'-'A');
            
            visited[a] += 1;
            if (visited[a]>m1){
                if (c1==a){
                    m1 = visited[a];
                }
                else{
                    m2 = m1;
                    m1 = visited[a];
                    c2 = c1;
                    c1 = a;
                }
            }
            else if (visited[a] > m2){
                m2 = visited[a];
                c2 = a;
            }
        }
        char cc1 = c1;
        char cc2 = c2;

        cout<<cc1<<cc2<<endl;
        cout<<m1<<","<<m2<<endl;
    }
    char res = c2;
    char capres = c2 + 'a' - 'A';
    cout<<capres<<'+'<<res<<':'<<visited[c2]<<endl;

    // int a = 'Z';
    // int z = 'z';
    // cout<<a<<endl;
    // cout<<z<<endl;

    // char aa = a;
    // char zz = a;
    // cout<<c2<<endl;
    // cout<<c2 + 'A' - 'a'<<endl;

    return 0;
}