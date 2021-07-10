#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Student{
private:
    string name;
    int age;
    string ID;
    float grade[4];
public:
    // Student(string names, int ages, string IDs, float  g[] ){
    //     name = names;
    //     age = ages;
    //     ID = IDs;
    //     for(int i=0; i<4; ++i)
    //         grade[i] = g[i];
    // }
    Student(string name, int age, string ID, float grade[] ){
        this->name = name;
        this->age = age;
        this->ID = ID;
        for(int i=0; i<4; ++i)
            this->grade[i] = grade[i];    
    };
    ~Student(){
        cout<<"destructor"<<endl;
    };
    int calc_grade(){
        float ss = 0;
        for(int i=0; i<4; ++i)
            ss += grade[i];

        cout<<"name: "<<name<<", ID: "<<ID<<" , age: "<<age<<" , grade: "<<int(ss/4)<<endl;
        return int(ss/4);

    }

};

int main(){
    float score[4] = {1,2,3,4};
    Student a("mike",5,"1",score);
    a.calc_grade();
    cout<<"return 0"<<endl;
    return 0;
}