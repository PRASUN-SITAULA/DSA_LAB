#include<iostream>

#define SIZE 50
template <class T>
class Deques{
    private:
    T front;
    T rear;
    T deque[SIZE];

    public:
    Deques(){
        front = -1;
        rear = -1;
    }

    T insertFromRear(T item);
    T deleteFromFront();
    T insertFromFront(T item);
    T deleteFromRear();
    T peek();

     bool checkOverFlow(){
        if( rear == SIZE - 1 && front == 0){
            std::cout<<"Stack is Full";
            return false;
        }
        return true;
    }

    bool checkUnderFlow(){
        if(front == rear){
            std::cout<<"Stack is empty";
            return false;
        }
        return true;
    }

};


template <class T>
T Deques<T>::insertFromRear(T item){
    if(checkOverFlow()){
        if(front == -1){
            front = 0;
        }
        rear++;
        deque[rear] = item;
    }
    return 0;
}


template <class T>
T Deques<T>::deleteFromFront(){
    if(checkUnderFlow()){
        if(front == SIZE -1){
            front = 0;
        }
        else
            front++;
        T item = deque[front];
        return item;
    }
    return 0;
}


template <class T>
T Deques<T>::insertFromFront(T item){
    if(checkOverFlow()){
        if(front == -1){
            front = 0;
            rear = 0;
        }
        else if(front == 0){
            front = SIZE - 1;
        }
        else
            front--;
        
        deque[front] = item;
    }
    return 0;
}


template <class T>
T Deques<T>::deleteFromRear(){
    if(checkUnderFlow()){
        T item = deque[rear];
        if(rear == SIZE -1)
            rear = 0;
        else
            rear++;
        return item;
    }
    return 0;
}


template <class T>
T Deques<T>::peek(){
    return deque[front];
}


int main(){
    Deques <int> deque;
    deque.insertFromRear(30);
    deque.insertFromFront(10);
    deque.insertFromRear(20);
    int item = deque.deleteFromFront();
    int item1 = deque.deleteFromRear();
    std::cout<<item<<std::endl;
    std::cout<<item1;
    return 0;
}
