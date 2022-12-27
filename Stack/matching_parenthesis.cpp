#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

string evaluate(string exp){
    stack<char> s;
    for(int i=0; i<exp.size(); i++){
        if(exp[i]=='('){;
            s.push('(');
        }

        if(exp[i]==')'){
            s.pop();
        }
    }

   if (s.empty()){
    cout<<"parenthesis are matched";
   }
   else{
    cout<<"parenthesis are not matched";
   }
}

int main(){
    evaluate("((A+B)*(C+D)");
    return 0;
}