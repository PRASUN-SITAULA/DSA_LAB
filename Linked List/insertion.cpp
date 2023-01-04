#include<iostream>

struct Node{
    int data;
    Node *next;
};


Node* start = NULL;
Node *temp = new Node;

int insertAtBeginning(int item){
    Node* newNode = new Node;
    newNode -> data = item;
    newNode -> next = start;
    start = newNode;
    return 0;
}

int insertAtEnd(int item){
    Node *newNode = new Node;
    temp = start;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> data = item;
    newNode -> next = NULL;
}


int insertAfterSpecificNode(){

    return 0;
}


int displayNodeElements(){
    temp = start;
    while(temp != NULL){
        std::cout<<temp -> data<<std::endl;
        temp = temp -> next;
    }
    return 0;
}

int main()
{
    insertAtBeginning(15);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtBeginning(45);
    insertAtEnd(10);
    insertAtEnd(5);
    displayNodeElements();

    return 0;
}