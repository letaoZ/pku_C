/*
编程题＃5：字符串插入
来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB、

描述
有两个字符串str和substr，str的字符个数不超过10，substr的字符个数为3。（字符个数不包括字符串结尾处的'\0'。）
将substr插入到str中ASCII码最大的那个字符后面，若有多个最大则只考虑第一个。

输入
输入包括若干行，每一行为一组测试数据，格式为

str substr

输出
对于每一组测试数据，输出插入之后的字符串。

样例输入
abcab eee
12343 555

output
abceeeab
12345553

提示
这题有多组输入，请参照第二题的提示依次读入和处理每一组数据。

如果使用了字符串函数，比如strlen，请包含cstring头文件 #include <cstring>。


*/