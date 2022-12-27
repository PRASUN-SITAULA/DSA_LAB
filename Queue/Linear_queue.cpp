#include<iostream>
#define SIZE 50

template <class T>
class Queue{
    private:
    T front;
    T rear;
    T queue[SIZE];

    public:
    Queue(){
        front = -1;
        rear = -1;
    }
    T enqueue(T item);
    T dequeue();
    T peek();

    bool checkOverFlow(){
        if(rear == SIZE - 1 && front == 0){
            std::cout<<"Stack is Full";
            return false;
        }
        return true;
    }

    bool checkUnderFlow(){
        if(front == rear){
            std::cout<<"Stack is Empty";
            return false;
        }
        return true;
    }
};

template <class T>
T Queue<T>::enqueue(T item){
    if(checkOverFlow()){
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = item;
    }
    return 0;
}

template <class T>
T Queue<T>::dequeue(){
    if(checkUnderFlow()){
        T item = queue[front];
        front++;
        return item;
    }
    return 0;
}

//returns first element
template <class T>
T Queue<T>::peek(){
    return queue[front];
}

int main(){
    Queue<int> items;
    items.enqueue(10);
    items.enqueue(20);
    items.enqueue(30);
    int item = items.dequeue();
    int item1 = items.peek();
    std::cout<<item<<std::endl;
    std::cout<<item1;
    return 0;
}