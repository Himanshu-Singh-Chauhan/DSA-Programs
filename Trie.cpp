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


class Trie
{
    public: static const int ALPHABET_SIZE = 26;

    private:
        class Node
        {
            public:
                int a = 778;
                char value;
                Node* *children = new Node*[ALPHABET_SIZE];
                int* *test;
                bool isEndOfWord;

                Node ()
                {
                    test = new int*[5];
                    for (int i = 0; i < ALPHABET_SIZE; i++)
                        children[i] = nullptr;

                    for (int i = 0; i < 5; i++)
                        test[i] = new int(i+3);


                    // print(test);
                    // print(&a, a);
                };

                Node (char value): value(value)
                {
                    Node();
                };
        };

        Node *root = new Node(' ');


    public: void insert(string word){

        Node *current = root;

        // print(root -> children);
        // for (int i = 0; i < ALPHABET_SIZE; i++)
        // {
        //     print(root -> children[i], i);
        // }
        // print(root -> test);
        for(int i = 0; i< 5; i++){
            print(*(root -> test[i]), i);
        }
        
{
            
            
        //     for (char ch: word)
        //     {
        //         int index = ch - 'a';

        //         print(current ->children[index], ch, word);
        //         if (current -> children[index] == nullptr)
        //             current -> children[index] = new Node(ch);
                
        //         current = current -> children[index];
        //     }

        //     current -> isEndOfWord = true;
                }
        }
};


int main()
{
    Trie *trie = new Trie;

    trie -> insert("cat");
    // trie -> insert("can");
    print("done");
    return 0;
}