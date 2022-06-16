/* 

    AVL TREES
    insert() - recursion, not iterative

*/


#include <iostream>

using std::cout;
using std::max;


// Python like print function
void print() { cout << '\n'; }
template <typename T, typename ...TAIL>
void print (const T &t, TAIL... tail)
{
    cout << t << ' ';
    print(tail...);
}


class AVLTree
{

private:

    class Node
    {
        public:
            int data;
            int height;
            Node *leftChild;
            Node *rightChild;

            Node(int data){
                this -> data = data;
                leftChild = nullptr;
                rightChild = nullptr;
                height = 0;
            }
    };


    // Variables
    Node *root;
    // End Variables

    Node* insert (Node *_root, int data){

        if (_root == nullptr)
            return new Node(data);

        Node &root = *_root; // to ease code writing

        if (data < root.data)
            root.leftChild = insert(root.leftChild, data);
        else
            root.rightChild = insert(root.rightChild, data);

        setHeight(&root);

        // balance factor = height(L) - height(R)
        // > 1 => left heavy (eg. 6 - 4)
        // < -1 => right heavy (eg. 4 - 6)

        _root = balance(_root);
        // returning new root
        return _root;
    }


    Node* balance(Node *_root){
        Node &root = *_root;

        if (isLeftHeavy(&root)){
            print( root.data ,"is left heavy" );

            if (balanceFactor(root.leftChild) < 0)
                root.leftChild = leftRotate(root.leftChild);

            return rightRotate(&root);
            // returnng new root
        }

        else if (isRightHeavy(&root)){
            print( root.data ,"is right heavy" );

            if (balanceFactor(root.rightChild) > 0)
                root.rightChild = rightRotate(root.rightChild);

            return leftRotate(&root);
            // returnng new root
        }

        // root is in balance
        // so return same root
        return _root;
    }


    Node* leftRotate(Node *_root){
        Node &root = *_root;

        Node &newRoot = *root.rightChild;
        root.rightChild = newRoot.leftChild;
        newRoot.leftChild = &root;

        setHeight(&root);
        setHeight(&newRoot);

        return &newRoot;
    }


    Node* rightRotate(Node *_root){
        Node &root = *_root;

        Node &newRoot = *root.leftChild;
        root.leftChild = newRoot.rightChild;
        newRoot.rightChild = &root;

        setHeight(&root);
        setHeight(&newRoot);

        return &newRoot;
    }


    void setHeight(Node *_node){
        Node &node = *_node;
        node.height = max(
                    height(node.leftChild),
                    height(node.rightChild)) + 1;
    }


    bool isLeftHeavy(Node *node){
        return balanceFactor(node) > 1;
    }


    bool isRightHeavy(Node *node){
        return balanceFactor(node) < -1;
    }


    int balanceFactor(Node *node){
        if (node == nullptr)
            return 0;
        return height(node -> leftChild) - height(node -> rightChild);
    }


    int height(Node *node){
        return node == nullptr ? -1 : (*node).height;
    }


public:

    AVLTree(){
        root = nullptr;
    }

    void insert(int data){
        root = insert(root, data);
    }

};


int main(int argc, char const *argv[])
{
    AVLTree tree;
    tree.insert(10);
    tree.insert(30);
    tree.insert(20);
    tree.insert(20);
    tree.insert(20);
    tree.insert(3);
    print("done");
    return 0;
}