#include <iostream>

void towerOfHanoi(int disks, char S, char A, char D){
    if ( disks == 1)
        std::cout<<S<<" to "<<D<<std::endl;
    else{
        towerOfHanoi(disks-1, S, D, A);
        towerOfHanoi(1, S, A, D);
        // std::cout<<S<<" to "<<D<<std::endl;
        towerOfHanoi(disks-1, A, S, D);
    }
    
}
int main(){
    int disks;
    std::cout<<"Enter the number of disks"<<std::endl;
    std::cin>>disks;
    towerOfHanoi(disks, 'S', 'A', 'D');
}