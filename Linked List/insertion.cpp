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
    return 0;
}


int insertAfterSpecificNode(int value, int item){
    temp = start;
    Node *newNode = new Node;
    while(temp -> data != value){
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
    newNode -> data = item;
    return 0;
}


int insertBeforeSpecificNode(int value, int item){
    temp = start;
    Node *newNode = new Node;
    Node *pretemp = new Node;
    pretemp = temp;
    while(temp -> data != value){
        pretemp = temp;
        temp = temp -> next;
    }
    // if the element is to be inserted before first element
    if(pretemp == start){
        newNode -> data = item;
        newNode -> next = start;
        start = newNode;
    }
    else{
        newNode -> next = pretemp -> next;
        pretemp -> next = newNode;
        newNode -> data = item;
    }
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
    insertAfterSpecificNode(30, 50);
    insertBeforeSpecificNode(45, 90);
    displayNodeElements();
    return 0;
}