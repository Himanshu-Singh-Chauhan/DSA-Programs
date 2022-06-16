#include <iostream>
#include <string>
#include <list>
#include <queue>

using std::cout;
using std::string;
using std::list;
using std::endl;
using std::max;
using std::queue;


// Python like print function
void print() { cout << '\n'; }
template <typename T, typename ...TAIL>
void print (const T &t, TAIL... tail)
{
    cout << t << ' ';
    print(tail...);
}


class BinarySearchTree
{
    private:

        class Node
        {
            public:

                int data;
                Node *leftChild;
                Node *rightChild;

                Node(int data){
                    this -> data = data;
                    leftChild = NULL;
                    rightChild = NULL;
                }
        };

        // Variables here
        Node *root;
        // End Variables

        void traversePreOrder(Node *root){
            if (root == nullptr)
                return;

            print(root -> data);
            traversePreOrder((*root).leftChild);
            traversePreOrder((*root).rightChild);
        }

        int height(Node *root){

            if (root == nullptr)
                return -1;

            if ( isLeaf(root) )
                return 0;

            int h = max(
                height(root ->leftChild), 
                height(root -> rightChild)) + 1;

            return h;
            
        }

        bool isLeaf(Node *node){
            return (node -> leftChild == nullptr && node -> rightChild == nullptr);
        }

        void getNodesAtDistance(Node *root, int distance, list<int> &nodesList){
            if (root == nullptr)
                return;

            if (distance == 0){
                nodesList.push_back(root -> data);
                return;
            }

            getNodesAtDistance(root -> leftChild, distance - 1, nodesList);
            getNodesAtDistance(root -> rightChild, distance - 1, nodesList);
        }

        list<int> getLeftView(Node *root)
        {
            list<int> leftviewlist;

            if (root == nullptr)
                return leftviewlist;
            
            queue<Node*> bfs_queue;
            bfs_queue.push(root);
            
            Node *node = nullptr;
            
            while( not bfs_queue.empty() ){
                int nodesAtCurrentLvl = bfs_queue.size();
                
                leftviewlist.push_back(bfs_queue.front() -> data);
                
                for (int i = 0; i < nodesAtCurrentLvl; i++){
                    node = bfs_queue.front();
                    
                    bfs_queue.pop();

                    // Important note:
                    {
                        // Do Not do the following
                            // if (node == NULL)
                            //     continue;
                        // Its better to check whether 
                        // the leftChild and rightChild 
                        // exists and then insert it, instead 
                        // of inserting null values, and then 
                        // checking for null because, then 
                        // you have to take care for a lot of extra
                        // edge cases, and the length of the 
                        // code will increase.
                    }
                    if (node -> leftChild)
                        bfs_queue.push(node -> leftChild);
               		if (node -> rightChild)
                        bfs_queue.push(node -> rightChild);
                    
                }
            }

            return leftviewlist;
        }

        int find_diameter(Node* root, int &diameter){
            if (root == nullptr)
                return 0;
            
            int left_height = find_diameter(root -> leftChild, diameter);
            int right_height = find_diameter(root -> rightChild, diameter);
            
            diameter = max(diameter, left_height + right_height);
            
            return 1 + max(left_height, right_height);
        }

        bool validateBST(Node *root, int range[]){
            if (root == nullptr)
                return true;
            
            if (root -> data >= range[0] and root -> data <= range[1]){
                int leftRange[] = {range[0], root -> data};
                int rightRange[] = {root -> data, range[1]};
            
                return true
                        and	validateBST(root -> leftChild, leftRange)
                        and validateBST(root -> rightChild, rightRange);
            }
            
            return false;
        }

    public:

        BinarySearchTree(){
            root = NULL;
        }

        void insert(int data){

            Node *node = new Node(data);

            if (root == NULL){
                root = node;
                return;
            }

            Node *current = root;

            while(true){
                
                if (data < (*current).data){

                    if ((*current).leftChild == NULL){
                        (*current).leftChild = node;
                        break;
                    }

                    current = (*current).leftChild;
                }

                else {   

                    if ((*current).rightChild == NULL){
                        (*current).rightChild = node;
                        break;
                    }

                    current = (*current).rightChild;
                
                }
            }
        }
        

        bool find(int data){
            Node *current = root;

            while (current != nullptr){
                if (data < (*current).data)
                    current = (*current).leftChild;
                else if (data > (*current).data)
                    current = (*current).rightChild;
                else
                    return true;
            }

            return false;
        }

        void traversePreOrder(){
            traversePreOrder(root);
        }

        int height(){
            return height(root);
        }

        list<int> getNodesAtDistance(int distance){
            list<int> nodesList;
            getNodesAtDistance(root, distance, nodesList);

            return nodesList;
        }

        void traverseLevelOrder(){
            for (int i = 0; i <= height(); i++){
                for (auto &&value : getNodesAtDistance(i))
                    print( value );
            }
        }

        list<int> traverseLevelOrderQueue(){

            list<int> nodesList;
            if (root == nullptr)
                return nodesList;

            queue<Node*> bfs_queue;
            bfs_queue.push(root);

            Node *node = nullptr;

            while( not bfs_queue.empty() ){
                node = bfs_queue.front();
                nodesList.push_back(node -> data);
                bfs_queue.pop();

                if (node -> leftChild)
                    bfs_queue.push(node -> leftChild);
                if (node -> rightChild)
                    bfs_queue.push(node -> rightChild);
            }

            return nodesList;
        }

        
        list<int> getLeftView(){
            return getLeftView(root);
        }

        

    int diameterOfBinaryTree()
    {
        int diameter;
        find_diameter(root, diameter);
        return diameter;
    }


    bool validateBST() {
        int range[] = {INT_MIN, INT_MAX};
        return true and validateBST(root, range);
    }
};



int main(int argc, char const *argv[])
{

    BinarySearchTree tree;
    tree.insert(7);
    tree.insert(4);
    tree.insert(9);
    tree.insert(1);
    tree.insert(6);
    tree.insert(8);
    tree.insert(10);
    tree.insert(1);

    // print(tree.find(10));
    print("height ->", tree.height());
    // tree.traversePreOrder();

    // for (int ele : tree.getNodesAtDistance(2)){
    //     print(ele);
    // }
    
    // tree.traverseLevelOrder();

    // for (int ele : tree.getLeftView())
    //     print(ele);

    print(tree.validateBST());

    return 0;
}
