#include<iostream>

int fibonacci(int n, int a=0, int b=1){
    if( n == 0)
        return a;
    if (n == 1)
        return b;
    return fibonacci(n-1, b, a+b);
}


int main(){
    int number;
    std::cout<<"Enter a number:"<<std::endl;
    std::cin>>number;
    for(int i=0; i<number; i++){
        std::cout<<fibonacci(i)<<" ";
    }
    return 0;
}