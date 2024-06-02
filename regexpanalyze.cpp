#include "regexpanalyze.h"
RegExpAnalyze::RegExpAnalyze(){
    CreateTable();
    curr_state=S0;
    next_state=S0;
}
void RegExpAnalyze::CreateTable(){
     table_state=vector<vector<int>>(AMOUNT_STATES,vector<int>(AMOUNT_CHARS,Se));

     //s0
     table_state[S0][' ']=S1;
     for(char i='a';i<='z';i++){
          table_state[S0][i]=S2;
     }
     for(char i='A';i<='Z';i++){
          table_state[S0][i]=S2;
     }
     table_state[S0]['-']=S2;

     //s1
     table_state[S1][' ']=S1;
     for(char i='a';i<='z';i++){
          table_state[S1][i]=S2;
     }
     for(char i='A';i<='Z';i++){
          table_state[S1][i]=S2;
     }
     table_state[S1]['-']=S2;

     //s2
     table_state[S2][' ']=S3;
     for(char i='a';i<='z';i++){
          table_state[S2][i]=S2;
     }
     for(char i='A';i<='Z';i++){
          table_state[S2][i]=S2;
     }
     table_state[S2]['-']=S2;
     table_state[S2][':']=S4;

     //s3
     table_state[S3][' ']=S3;
     table_state[S3][':']=S4;

     //s4
     table_state[S4][' ']=S5;

     //s5
     table_state[S5][' ']=S6;
     for(char i='a';i<='z';i++){
          table_state[S5][i]=S6;
     }
     for(char i='A';i<='Z';i++){
          table_state[S5][i]=S6;
     }
     for(char i='0';i<='9';i++){
          table_state[S5][i]=S6;
     }
     table_state[S5]['.']=S6;
     table_state[S5]['#']=S6;

     //s6
     table_state[S6][' ']=S6;
     for(char i='a';i<='z';i++){
          table_state[S6][i]=S6;
     }
     for(char i='A';i<='Z';i++){
          table_state[S6][i]=S6;
     }
     for(char i='0';i<='9';i++){
          table_state[S6][i]=S6;
     }
     table_state[S6]['.']=S6;
     table_state[S6]['#']=S6;
     table_state[S6][';']=S7;

}

bool RegExpAnalyze::Analyse(string str){
    curr_state=S0;
    next_state=S0;
    for(int i=0;i<str.size();i++){
        curr_state=table_state[curr_state][str[i]];
    }
    if(curr_state==S7){
        return true;
    }
    else{
        return false;
    }
}

QString RegExpAnalyze::GetRandomStr(){
    QString ans="";
    curr_state=S0;
    while(curr_state!=S7){
        int simbol=rand()%128;

        if(curr_state==S3){
            int r=rand()%2;
            if(r)
                simbol=' ';
            else
                simbol=':';
            next_state=table_state[curr_state][simbol];
        }
        else if(curr_state==S4){
            simbol=' ';
            next_state=table_state[curr_state][simbol];
        }
        else{
            next_state=table_state[curr_state][simbol];
            while(next_state==Se){
                simbol=rand()%128;
                next_state=table_state[curr_state][simbol];
            }
        }
        curr_state=next_state;
        ans+=simbol;
    }
    return ans;
}




















