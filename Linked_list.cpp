#include <iostream>
#include <string>
#include <list>

// using namespace std;
using std::string;
using std::list;

// function signatures
string arrayToString(list<int> array);


class Linked_list {

    private:

        class Node{

            public:

                int data;
                Node *next;

                Node(int data){
                    this -> data = data;
                    this -> next = NULL;
                }
        };

        Node *first = NULL;
        Node *last = NULL;

        int size;
        
    public:

        // Constructor
        Linked_list(){
            first = NULL;
            last = NULL;
            size = 0;
        }


        void addFirst(int data){
            Node *node = new Node(data);

            if ( size == 0 )
                first = last = node;
            else
            {
                (*node).next = first;
                first = node;
            }

            size = size + 1;
            
        }

        void addLast(int data){
            Node *node = new Node(data);

            if (size == 0)
                first = last = node;
            else
            {
                (*last).next = node;
                last = node;
            }

            size = size + 1;
        }

        list<int> toArray(){
            list <int> array;

            Node *current = first;

            while ( current != NULL ){
                array.push_back(current -> data);
                current = current -> next;
            }

            return array;
        }

};

int main(int argc, char const *argv[])
{
    // linked list
    Linked_list mylist;

    mylist.addFirst(10);
    mylist.addFirst(20);
    mylist.addFirst(30);
    mylist.addFirst(40);

    mylist.addLast(10);
    mylist.addLast(20);
    mylist.addLast(30);
    mylist.addLast(40);

    string items = arrayToString(mylist.toArray());
    std::cout << items;

    return 0;
}


string arrayToString(list<int> array){
    string array_str;

    for (int i: array)
        array_str += std::to_string(i) + " ";

    return array_str;
}

