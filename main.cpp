#include <QCoreApplication>
#include <QDebug>
#include <string>
#include "regexpanalyze.h"
#include <iostream>
#include <set>
using namespace std;
bool CheckSimvols(string str){
    set<char> s;
    for(char i='0';i<='9';i++){
        s.insert(i);
    }
    for(char i='a';i<='z';i++){
        s.insert(i);
    }
    for(char i='A';i<='Z';i++){
        s.insert(i);
    }
    s.insert('.');
    s.insert('#');
    s.insert(';');
    s.insert(':');
    s.insert(' ');
    s.insert('-');
    for(auto e:str){
        if(s.find(e)==s.end()){
            return false;
        }
    }
    return true;
}
int main(int argc, char *argv[])
{
    srand(time(0));
    QCoreApplication a(argc, argv);
    string str="";
    float f=10.;
    RegExpAnalyze analyzator;
    while(true){
        str="";
        qDebug()<<"Enter <<G>> for auto generation string;";
        qDebug()<<"Enter <<Q>> for quit;";
        qDebug()<<"Or enter the string for check:";
        std::getline(std::cin, str);
        if(str=="Q")
            break;
        else if(str=="G"){
            qDebug()<<analyzator.GetRandomStr();
        }
        else{
            if(!CheckSimvols(str))
                qDebug()<<"There are characters not from the alphabet! Try again.";
            else{
                bool result=analyzator.Analyse(str);
                if(result)
                    qDebug()<<"The string is correct.";
                else{
                    qDebug()<<"The string is incorrect.";
                }

            }
        }
        qDebug()<<"\n\n\n";
    }
    return 0;
}


//Examples able CSS  attributes:
/*
background: #0C0C0C;
background: red;
clear: left;
z-index: 5;
height: 10 pt;
*/
