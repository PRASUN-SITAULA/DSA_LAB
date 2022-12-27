#include<iostream>

int calcFactorial(int n){
    if( n == 0){
        return 1;
    }
    else{
        return n*calcFactorial(n-1);
    }
}

int main(){
    int number;
    std::cout<<"Enter a number: "<<std::endl;
    std::cin>>number;
    std::cout<<"The factorial of "<<number<< " is "<<calcFactorial(number);
    return 0;
}