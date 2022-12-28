#include <iostream>

int factorial(int, int);
int calcFactorial(int n){
   return factorial(n, 1);
}

int factorial(int n, int res){
    if ( n == 1)
        return res;
    else
        return factorial(n-1 , n*res);
}

int main(){
    int number;
    std::cout<<"Enter a number"<<std::endl;
    std::cin>>number;
    std::cout<<"The factorial of "<<number<<" is "<<calcFactorial(number);
}