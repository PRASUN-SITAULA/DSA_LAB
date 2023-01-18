#include<iostream>
struct Node{
    int data;
    Node *next;
};

Node* rear = NULL;
Node *temp = new Node;

//insertion operations

int enqueue(int item){
    Node *newNode = new Node;
    temp = rear;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
    newNode -> data = item;
    newNode -> next = NULL;
    return 0;
}


int displayNodeElements(){
    temp = rear;
    while(temp != NULL){
        std::cout<<temp -> data<<std::endl;
        temp = temp -> next;
    }
    return 0;
}


//deletion operations
int dequeue(){
    if(rear == NULL){
        std::cout<<"List is empty";
    }
    temp = rear;
    rear = rear -> next;
    int deletedElement =  temp->data;
    free (temp);
    return deletedElement;
}






int main()
{
    enqueue(10);
    enqueue(5);
    dequeue();
    displayNodeElements();
    return 0;
}