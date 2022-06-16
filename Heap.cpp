// MAX Heap

#include <iostream>
#include <string>
#include <list>
#include <vector>

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

// Heap means MAX Heap
// this is NOT a min heap

class Heap
{
    private:
        int *items;
        int capacity;
        int size;

        void swap(int first, int second){
            int temp = items[first];
            items[first] = items[second];
            items[second] = temp;
        }

        int parent(int index){
            return (index - 1) / 2;
        }

        int leftChildIndex(int index){
            return (index * 2) + 1;
        }

        int rightChildIndex(int index){
            return (index * 2) + 2;
        }

        int leftChild(int index){
            return items[leftChildIndex(index)];
        }

        int rightChild(int index){
            return items[rightChildIndex(index)];
        }

        void bubbleUp(){
            {
           /*  HERE we should NOT calcualate parent
            and store it in a var and then use it
            in loop, we should calculate it dynamically
            in loop condition.
            This is very IMPORTANT, bcoz in each
            iteration, the index changes, so we should
            recalculate the index of the parent.
            int parentIndex = parent(index); -> WRONG */
            }

            int index = size;

            while (index > 0 and items[index] > items[parent(index)]){
                swap(index, parent(index));
                index = parent(index);
            }
        }

        void bubbleDown(){
            int index = 0;

            while(index <= size and not isValidParent(index))
            {
                int largerChildIdx = largerChildIndex(index);
                swap(index, largerChildIdx);
                index = largerChildIdx;
            }
        }

        bool isValidParent(int index){

            if (not hasLeftChild(index))
                return true;

            bool isValid = items[index] >= leftChild(index);

            if (hasrightChild(index))
                isValid = isValid and items[index] >= rightChild(index);

            return isValid;
        }

        int largerChildIndex(int index){
            if (not hasLeftChild(index))
                return index;

            if (not hasrightChild(index))
                return leftChildIndex(index);

            return (leftChild(index) > rightChild(index)) ?
                        leftChildIndex(index) : rightChildIndex(index);
        }

        bool hasLeftChild(int index){
            return leftChildIndex(index) <= size;
        }

        bool hasrightChild(int index){
            return rightChildIndex(index) <= size;
        }


// PUBLIC Section

    public:
        Heap(int capacity){
            items = new int[capacity];
            this -> capacity = capacity;
            size = 0;
        }

        void insert(int data){

            if (isFull()){
                print("Heap full, can't insert ", data);
                return;
            }

            items[size] = data;
            bubbleUp();
            size = size + 1;
        }

        int remove(){
            /* We dont need any parameterAlways removing root node
            holding the largest value */

            if (isEmpty()){
                print("Heap empty, cant remove");
                return -1;
            }

            int root = items[0];

            items[0] = items[size - 1];
            size = size - 1;

            bubbleDown();

            return root;
        }

        bool isFull(){
            return size == capacity;
        }

        bool isEmpty(){
            return size == 0;
        }


};



int main()
{

    Heap heap(10);
    heap.insert(10);
    heap.insert(5);
    heap.insert(17);
    heap.insert(4);
    heap.insert(22);
    // heap.remove();


    // Heap Sort
    std::vector<int> numbers = {5, 3, 10, 1, 4, 2};
    Heap sortingheap(numbers.size());

    for (int &number : numbers)
        sortingheap.insert(number);

    // Direct printing
    // while ( not sortingheap.isEmpty() )
    //     print(sortingheap.remove());

    // Storing back in numbers
    for (int i = numbers.size() - 1; i >= 0; i--)
        numbers[i] = sortingheap.remove();

    for (int num: numbers)
        print(num);

    print();

    return 0;
}