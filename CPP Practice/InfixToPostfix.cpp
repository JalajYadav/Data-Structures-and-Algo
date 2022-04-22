#include<bits/stdc++.h>
using namespace std;
int weight(char c){
    if(c == '^'){
        return 3;
    }else if(c == '*' or c == '/'){
        return 2;
    }else if(c == '+' or c == '-'){
        return 1;
    }else{
        return (-1);
    }
}
void infixToPostfix(string in){
    stack <char> temps;
    string out = "";
    for(int i = 0;i<in.length();i++){
        //To check for a-z and A-Z
        if((in[i]>='a' and in[i]<='z')or
        (in[i]>='A' and in[i]<='Z')){
            out+=in[i];
        }
        else if(in[i]=='('){
            temps.push('(');
        }
        else if(in[i]==')'){
            while(temps.top()!='('){
                out+=temps.top();
                temps.pop();
            }
            temps.pop();
        }else{
            while(!temps.empty() and weight(temps.top())>=weight(in[i])){
                out+=temps.top();
                temps.pop();
            }
            temps.push(in[i]);
        }
    }
    while(!temps.empty()){
            out+=temps.top();
            temps.pop();
        }
    cout<<"Postfix Expression is:"<<out<<endl;
}
int main(int argc, char const *argv[])
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
