#include <iostream>

#define SIZE 50

template <class T>

class CircularQueue{
    private:
    T queue[SIZE];
    T front;
    T rear;

    public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }
    T enqueue(T item);
    T dequeue();
    T peek();

    bool checkOverFlow(){
        if((rear == SIZE - 1 && front == 0) || (front == rear + 1)){
            std::cout<<"Overflow";
            return false;
        }
        return true;
    }

    bool checkUnderFlow(){
        if(front == -1 || front == rear){
            std::cout<<"UnderFlow";
            return false;
        }
        return true;
    }
};


template <class T>
T CircularQueue<T>::enqueue(T item){
    if(checkOverFlow()){
        if(front == -1 || rear == -1){
            front = 0;
            rear = 0;
        }
        else if(rear == SIZE-1 && front != 0){
            rear = 0;
        }
        else{
        rear++;
        }
        queue[rear] = item;
    }
    return 0;
}

template <class T>
T CircularQueue<T>::dequeue(){
    if(checkUnderFlow()){
        T item = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if (front == SIZE-1){
            front = 0;
        }
        else{
            front++;
        }
        return item;
    }
    return 0;
}

template <class T>
T CircularQueue<T>::peek(){
    return queue[front];
}

int main(){
    CircularQueue<int> queue;
    queue.enqueue(10);
    queue.enqueue(80);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.dequeue();
    queue.dequeue();
    std::cout<<queue.peek();
    return 0;
}