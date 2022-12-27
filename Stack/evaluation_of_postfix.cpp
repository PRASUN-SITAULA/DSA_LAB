#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>
#include <stack>

using namespace std;
//stack push and pop operation

void evaluate (string expression){
    stack<int> s;
    char op;
    int temp1, temp2;
    for (int i=0; i<expression.size(); i++){
        if(isdigit(expression[i])){
            s.push(int(expression[i]) - 48);
        }
        else{
            char c = expression[i];
            temp1= s.top();
            s.pop();
            temp2 = s.top();
            s.pop();   
            if(c == '+'){
                s.push(temp1 + temp2);
            }
            else if(c == '-'){
                s.push(temp1 - temp2);
            }
            else if(c == '*'){
                s.push(temp1 * temp2);
            }
            else if(c == '/'){
                s.push(temp1 / temp2);
            }
            else if(c == '^'){
                s.push(pow(temp1, temp2));
            }
            else{
                break;
            }
        }
    }
    printf("%d", s.top());
}

int main(){
    evaluate("25*7+");
    return 0;
}