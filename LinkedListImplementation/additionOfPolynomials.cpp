#include<iostream>

struct Node{
    int coefficient;
    int exponent;
    Node *next;
};

Node *firstPolynomial = new Node;
Node *secondPolynomial = new Node;
Node *resultPolynomial = new Node;
Node *startFirst = NULL;
Node *startSecond = NULL;
Node *startResult = NULL;


int getFirstPolynomialData(int coeff, int exp){
    Node *temp = NULL;
    while(temp != NULL){
        temp = temp -> next;
    }
    firstPolynomial -> coefficient = coeff;
    firstPolynomial -> exponent = exp;

    if(temp == NULL){
        temp = firstPolynomial;
        startFirst = firstPolynomial;
        firstPolynomial -> next = NULL;
    }
    else{
        temp -> next = firstPolynomial;
        firstPolynomial -> next = NULL;
    }
}


int getSecondPolynomialData(int coeff, int exp){
    Node *temp = NULL;
    while(temp != NULL){
        temp = temp -> next;
    }
    secondPolynomial -> coefficient = coeff;
    secondPolynomial -> exponent = exp;

    if(temp == NULL){
        temp = secondPolynomial;
        startSecond = secondPolynomial;
        secondPolynomial -> next = NULL;
    }
    else{
        temp -> next = secondPolynomial;
        secondPolynomial -> next = NULL;
    }
}

int addPolynomial(int coeff, int exp){
    Node *temp = NULL;
    while(temp != NULL){
        temp = temp -> next;
    }
    resultPolynomial -> coefficient = coeff;
    resultPolynomial -> exponent = exp;

    if(temp == NULL){
        temp = resultPolynomial;
        startResult = resultPolynomial;
        resultPolynomial -> next = NULL;
    }
    else{
        temp -> next = resultPolynomial;
        resultPolynomial -> next = NULL;
    }
}


int result(){
    Node *p = startFirst;
    Node *q = startSecond;
    while(firstPolynomial -> next != NULL && secondPolynomial -> next != NULL){
        if(p->exponent == q->exponent){
            addPolynomial(p->coefficient + q->coefficient, p -> exponent );
            p = p -> next;
            q = q -> next;
        }

        else if( p->exponent < q->exponent){
            addPolynomial(q->coefficient, q -> exponent );
            q = q -> next;
        }
        else {
            addPolynomial(p->coefficient, p -> exponent );
            p = p -> next;
        }
        
    }
}


int main(){
    int n,i=0,coeff,exp;
    std::cout<<"Enter the number of terms in equations"<<std::endl;
    std::cin>>n;
    while(i != n){
        std::cout<<"Enter the cofficient and exponent of first polynomial"<<std::endl;
        std::cin>>coeff;
        std::cout<<std::endl;
        std::cin>>exp;
        getFirstPolynomialData(coeff, exp);
        i++;
    }

    i = 0;
     while(i != n){
        std::cout<<"Enter the cofficient and exponent of second polynomial"<<std::endl;
        std::cin>>coeff;
        std::cout<<std::endl;
        std::cin>>exp;
        getSecondPolynomialData(coeff, exp);
        i++;
    }
    result();
    

    return 0;
}