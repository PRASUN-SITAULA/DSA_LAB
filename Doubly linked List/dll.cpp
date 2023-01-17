#include<iostream>
struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node* start = NULL;
Node *temp = new Node;

//insertion operations
int insertAtBeginning(int item){
    Node* newNode = new Node;
    newNode -> data = item;
    newNode -> next = start;
    newNode -> prev = NULL;
    start = newNode;
    return 0;
}

int insertAtEnd(int item){
    Node *newNode = new Node;
    temp = start;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    newNode -> prev = temp;
    temp -> next = newNode;
    newNode -> data = item;
    newNode -> next = NULL;
    return 0;
}


int insertAfterSpecificNode(int value, int item){
    temp = start;
    Node *newNode = new Node;
    newNode -> data = item;
    while(temp -> data != value){
        temp = temp -> next;
    }
    //if the element is to be inserted after final node
    if(temp -> next == NULL){
        newNode -> prev = temp;
        temp -> next = newNode;
        newNode -> next = NULL;
    }
    else{
        newNode -> prev = temp; 
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
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
        newNode -> prev = NULL;
        start = newNode;
    }
    else{
        newNode -> prev = pretemp;
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


//deletion operations
int deleteFromBeginning(){
    if(start == NULL){
        std::cout<<"List is empty";
    }
    temp = start;
    start = start -> next;
    start -> prev = NULL;
    int deletedElement =  temp -> data;
    free (temp);
    return deletedElement;
}

int deleteFromEnd(){
    if(start == NULL){
        std::cout<<"List is empty";
    }
    temp = start;
    while(temp -> next -> next != NULL){
        temp = temp -> next;
    }
    int removedElement = temp -> next -> data;
    free (temp->next);
    temp -> next = NULL;
    return removedElement;
}

int deleteAfterSpecificNode(int element){
    temp = start;
    Node *pretemp;
    while(temp -> data != element){
        temp = temp ->next;
    }
    pretemp = temp -> next ->next;
    temp -> next -> next -> prev = temp;
    int removedElement = temp -> next ->data;
    free(temp -> next);
    temp -> next = pretemp;
    return removedElement;
}

int deleteBeforeSpecificNode(int element){
    temp = start;
    Node *preptr;
    while(temp -> next -> data != element){
        preptr = temp;
        temp = temp -> next;
    }
    preptr -> next = temp -> next;
    temp -> next -> prev = preptr;
    int removedElement = temp -> data;
    free(temp);
    return removedElement;
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
    insertAfterSpecificNode(5, 68);
    deleteFromBeginning();
    deleteFromEnd();
    deleteAfterSpecificNode(30);
    deleteBeforeSpecificNode(20);
    displayNodeElements();
    return 0;
}