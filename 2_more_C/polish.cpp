
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

float parse_input(string x){
    string parsed;
    stack<string> sk;
    vector<string> ops{"+","-","*","/"};

    // parsing single char deliminater
    stringstream input_stringstream(x);
    bool opFlag =false;
    bool numFlag =false;


    while(getline(input_stringstream, parsed, ' ')){
        // compare returns 0 if equal
        opFlag = false;
        cout<<"parsed: "<<parsed<<endl;
        for(auto o:ops){
            if(!parsed.compare(o)){
                sk.push(parsed);
                opFlag = true;
                numFlag = false;
                break;
            }
        }
        if(opFlag)
            continue;

        //numFlag means previous parse gets a number and this parse is a number as well
        if(numFlag){
            string s1;
            string op12;
            do{     
                s1 = sk.top();
                sk.pop();
                op12 = sk.top();
                sk.pop();
                float num2 = stof(parsed);
                float num1 = stof(s1);
                
                if(!op12.compare("*"))
                    num1 = num1*num2;
                if(!op12.compare("+"))
                    num1 = num1+num2;
                if(!op12.compare("-"))
                    num1 = num1-num2;
    
                if(!op12.compare("/"))
                    num1 = num1/num2;
                
                parsed = to_string(num1);
                if (sk.empty())
                    break;
                s1 = sk.top();
                // make sure all op num num are process before going to next step
            } while(s1.compare("*") && s1.compare("/") && s1.compare("-") && s1.compare("+"));
            sk.push(parsed);
            opFlag = false;
            numFlag = true;
        }
        else{ // the first number comes in
            sk.push(parsed);
            opFlag = false;
            numFlag = true;
        }
    }
    float res = stof(sk.top());
    sk.pop();
    return res;
}

int main(){

    string x = "* * + 11.0 12.00 + 24.0 35.0 2";
    x = "* / + 12 36 + 1 3 - 15 8";
    float res= parse_input(x);

   

    cout<<res<<endl;
    return 0;
}