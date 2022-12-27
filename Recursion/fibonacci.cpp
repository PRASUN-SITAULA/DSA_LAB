#include <iostream>

int fibonacci(int n){
    int item;
    if ( n == 0 ){
        return 0;
    }
    else if ( n == 1){
        return 1;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);  
    }
    
}

int main(){
    int number, m = 0;
    std::cout<<"Enter a number "<<std::endl;
    std::cin>>number;
    while( m<= number){
        std::cout<<fibonacci(m)<<" ";
        m++;
    }
    return 0;
}