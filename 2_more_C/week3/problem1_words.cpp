/*
编程题＃1：单词翻转
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
输入一个句子（一行），将句子中的每一个单词翻转后输出。

输入
只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。所谓单词指的是所有不包含空格的连续的字符。

这道题请用cin.getline输入一行后再逐个单词递归处理。

输出
翻转每一个单词后的字符串，单词之间的空格需与原文一致。

样例输入
hello    world.

output
olleh    .dlrow
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reverse_word(char *start, char *end){
    while(start<end){
        // cout<<"swap"<<endl;
        // cout<<*start<<*end<<endl;
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start ++;
        end --;
    }


}

int main(){

    char x[10000];
    cin.getline(x,10000,'\n');
    char *start = x;
    char *end  = x;
    // bool flagStart = false;
    // bool flagEnd = false;
    while (*start ){
        // cout<<*start<<endl;
        if( (*start >= 'a' && *start <= 'z') || (*start >= 'A' && *start <= 'Z') ){
            while(*end && *end!=' ' ) {
                // cout<<*end<<endl;
                end++;
                }
            // cout<<"ended"<<endl;
            // cout<<start<<endl;
            // cout<<end<<endl;
            end --;

            char * p1 = start;
            char * p2 = end;
            reverse_word(p1, p2);
            start = end;
            // cout<<"ended2"<<endl;


        }
        start ++;
        end ++;


    }


    cout<<x<<endl;



    return 0;
}