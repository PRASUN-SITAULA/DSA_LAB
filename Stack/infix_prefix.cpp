#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

int checkPrecedance(char op){
    if (op== '^')
        return 3;
    else if (op== '/' || op== '*')
        return 2;
    else if (op== '+' || op== '-')
        return 1;
    else
        return -1;
}

string reverseString(string exp){
    string reversedString = "";
    for(int i = exp.size(); i>0; i--){
        reversedString += exp[i];
    }
    return reversedString;
}

void toPreFix(string exp){
    string Prefix_exp;
    stack<char> s;
    for(int i=0; i<exp.size(); i++){
        char c = exp[i];
        if(c == ')'){
            s.push(c);
        }
        else if((c >= 'a' && c<='z') || (c>='A' && c<='Z')){
            Prefix_exp += c;
        }
        else if (c == '(') {
            while (s.top() != ')') {
                Prefix_exp += s.top();
                s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && checkPrecedance(c) <= checkPrecedance(s.top())) {
                Prefix_exp += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    Prefix_exp = reverseString(Prefix_exp);;
    cout<<Prefix_exp;
}

int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    exp = '(' + exp + ')';
    exp = reverseString(exp);
    toPreFix(exp);
    return 0;
}