#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::string;
using std::list;
using std::endl;

// Python like print function
void print() { cout << '\n'; }
template <typename T, typename ...TAIL>
void print (const T &t, TAIL... tail)
{
    cout << t << ' ';
    print(tail...);
}

class Queue
{
private:
    int *queue;
    int front = 0;
    int rear = 0;
    int size = 0;
    int capacity;

public:
    Queue(int capacity){
        queue = new int[capacity];
        this -> capacity = capacity;
    }

    void enqueue(int data){
        if (isFull()){
            print("Queue full, cant enqueue", data);
            return;
        }

        queue[rear] = data;
        rear = (rear + 1) % capacity;
        size = size + 1;
    }

    int dequeue(){
        if (isEmpty()){
            print("Queue Empty");
            return INT_MIN;
        }

        int item = peek();
        queue[front] = 0; // clearing item in array
        front = (front + 1) % capacity;
        size = size - 1;

        return item;
    }

    int peek(){
        return queue[front];
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

};


int main()
{
    Queue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.enqueue(60);
    queue.enqueue(70);
    print(queue.dequeue());
    queue.enqueue(80);

    print();

    return 0;
}