#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::list;
using std::string;

// Python like print function
void print() { cout << '\n'; }
template <typename T, typename... TAIL>
void print(const T &t, TAIL... tail)
{
    cout << t << ' ';
    print(tail...);
}

class PriorityQueue
{

    /* 
        insert : O(n)
        delete : O(1)
    */

    /* assuming that the larger number have
    a higher priority and they should be processed first.
    So that we don't have to maintain the first and rear
    pointer, we can make use of size var. If you want
    to have smaller number have a higher priority and 
    you need front and rear pointer. */
private:
    int *queue;
    int size = 0;
    int capacity;

public:
    PriorityQueue(int capacity) : capacity(capacity)
    {
        queue = new int[capacity];
        // this -> capacity = capacity;
    }

    void add(int data)
    {
        if (isFull()){
            print("Queue full, can't enqueue ", data);
            return;
        }


        int pos = shiftItemsToInsert(data);

        queue[pos] = data;
        size = size + 1;
    }

    int remove(){
        if (isEmpty()){
            print("Queue empty");
            return INT_MIN;
        }

        int item = queue[size - 1];
        size = size - 1;
        return item;
    }

    int shiftItemsToInsert(int data){

        int i; // if declared in loop, then scoped to loop
        // can't use after loop which we want.
        for (i = size - 1; i >= 0; i--)
            if (queue[i] > data)
                queue[i + 1] = queue[i];
            else
                break;

        return i + 1;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    PriorityQueue pqueue(5);
    pqueue.add(5);
    pqueue.add(3);
    pqueue.add(6);
    pqueue.add(1);
    pqueue.add(4);
    // pqueue.add(10);

    while (!pqueue.isEmpty())
        print(pqueue.remove());

    print();

    return 0;
}