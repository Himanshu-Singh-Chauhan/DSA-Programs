#include <iostream>
#include <string>
#include <list>
#include "Heap.cpp"

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


class PriorityQueueHeap
{

    /* This implementation of priority queue is 
    essentially a wraper around the heap class, and
    YES, this is how priority queues are implemented
    using a heap. */

    private:

        Heap *heap;
        int capacity;
        
    public:
        PriorityQueueHeap(int capacity) : capacity(capacity)
        {
            heap = new Heap(capacity);
        }

        void enqueue (int data){
            heap -> insert(data);
        }

        int dequeue(){
            return heap -> remove();
        }

        bool isEmpty(){
            return heap -> isEmpty();
        }

};


int main()
{
    
    return 0;
}