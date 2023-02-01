#include<iostream>
struct Node{
    int data;
    Node *next;
};
Node* top = NULL;
Node *temp = new Node;
//push operations
int push(int item){
    Node* newNode = new Node;
    newNode -> data = item;
    newNode -> next = top;
    top = newNode;
    return 0;
}
//pop operations
int pop(){
    if(top == NULL){
        std::cout<<"List is empty";
    }
    temp = top;
    top = top -> next;
    int deletedElement =  temp->data;
    free (temp);
    return deletedElement;
}
int displayNodeElements(){
    temp = top;
    while(temp != NULL){
        std::cout<<temp -> data<<std::endl;
        temp = temp -> next;
    }
    return 0;
}
int main()
{
    int deleteItem;
    push(15);
    push(20);
    push(30);
    push(45);
    std::cout<<"The delete item is "<<pop()<<std::endl;
    displayNodeElements();
    return 0;
}