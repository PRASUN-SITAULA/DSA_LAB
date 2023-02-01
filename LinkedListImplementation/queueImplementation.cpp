#include<iostream>
struct Node{
    int data;
    Node *next;
};
Node *rear = NULL;
Node *front = NULL;
//insertion operations
int enqueue(int item){
    Node *newNode = new Node;
    newNode -> data = item;
    if(front == NULL){
        front = newNode;
        rear = newNode;
        front -> next = NULL;
        rear -> next = NULL;
    }
    else{
        rear -> next = newNode;
        rear = newNode;
        rear -> next = NULL;
    }
    return 0;
}
//deletion operations
int dequeue(){
    Node *temp = new Node;
    if(front == NULL){
        std::cout<<"Queue is empty";
    }
    temp = front;
    int deletedElement =  front->data;
    front = front -> next;
    delete (temp);
    return deletedElement;
}
int displayNodeElements(){
    Node *temp = new Node;
    temp = front;
    while(temp != NULL){
        std::cout<<temp -> data<<std::endl;
        temp = temp -> next;
    }
    return 0;
}

int main()
{   enqueue(10);
    enqueue(5);
    std::cout<<"The deleted element is "<<dequeue()<<std::endl;
    displayNodeElements();
    return 0;}