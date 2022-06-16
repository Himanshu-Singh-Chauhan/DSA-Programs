/* 
    Graph implementation using adjacency list, 
    hashmaps, C++ std::lists(doubly linked list)

    NOTE: Directed graph.
*/

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <set>
#include <stack>
#include <queue>

using std::cout;
using std::string;
using std::list;
using std::unordered_map;
using std::set;
using std::stack;
using std::queue;
using std::endl;

// Python like print function
void print() { cout << '\n'; }
template <typename T, typename ...TAIL>
void print (const T &t, TAIL... tail)
{
    cout << t << ' ';
    print(tail...);
}

class Directed_Graph
{
private:
    class Node {
        public: string label;
        public: Node(string label) : label(label){};
    };

    unordered_map<string, Node*> nodes;
    unordered_map<Node*, list<Node*>*> adjacency_list;

    private: void pretty_print_LL(list<Node*> &_list){
        for (auto node: _list) {
            cout << node -> label << " ";
        }
        print();
    }

    private: bool isValidNode(string label) {
        return nodes.count(label);
    }

public:
    void addNode(string label){
        Node *node = new Node(label);

        /* Docs / Notes : */ {
        /* 
            Note: the following line works
            like putIfAbsent method in JAVA.
            It will only add the label key
            if it does not exist in hashmap.
            If it already exists, nothing is done.
            So, careful, adding the same node or 
            edge between two nodes that already exists
            will do nothing, no warning are given. 

        nodes[label] = node;

            Since node is a pointer
            the address will be random every time
            regardless of the label, so following
            line is going to run no matter what.

        adjacency_list[node] = new list<Node*>;

            So finally, lets check if label already 
            exists or not, if yes, throw warning
            and return.
        */ 
       }

        if (nodes[label]){
            print(label, "already exits");
            return;
        }

        /* insert method is not working for
        reason, key is getting inserted
        but value which is node is 0x0.

        nodes.insert({label, node});

        so even if node exists, checking 
        to see if it exists or not like 
        this -> not dict[node] will result
        in true if it exists, which is not 
        what we want. */


        // nodes.insert({label, node}); // not working, see above comment.
        nodes[label] = node;
        // print(nodes[label]);
        adjacency_list.insert({node, new list<Node*>});
    }

    void addEdge(string from, string to){
        Node *fromNode = nodes[from];

        if (not fromNode)
        {
            print(from," node does not exists!");
            return;
        }

        Node *toNode = nodes[to];
        if (not toNode)
        {
            print(to," node does not exists!");
            return;
        }

        adjacency_list.at(fromNode) -> push_back(toNode);

        /*  IF our graph is NON directed
            we also add inverse relationship.
            that is toNode to fromNode.

        adjacency_list.at(toNode) -> push_back(fromNode);
        */
    }

    public: void print_graph() {
        for (auto node: nodes){
            auto targets = adjacency_list.at(node.second);
            if (not targets -> empty())
            {
                cout << node.first << " : ";
                pretty_print_LL(*targets);
            }
        }
    }

    public: void removeNode(string label) {
        Node *node = nodes[label];

        if (not node) 
            return; /* we simply return without throwing
            exception or printing any warnings
            bcoz if someone passes an invalid
            argument, its not the end of the world
            maybe that node was already deleted, we
            dont wanna yell at them. There's no harm
            to remove an already removed node. 
            In CONTRAST, in the addEdge method, 
            if someone tries to establish a connection
            between two nodes, and if any node is not
            valid, we have to tell them.*/

        /* Since this is a directed graph
            we cannot just get the connected 
            nodes from the list of node to be 
            removed and then just remove the
            connection to the node from those nodes.
            ...in other words:
            we cannot optimize it in following way:
            conn_nodes = adjacencny_lsit[node]
            // iterating just over the connected nodes 
            // to target node to remove target node
            // from connected nodes list.
            for n in conn_nodes 
                adjacency_list[n].remove(node)
            // finally remove target node itself
            // from the adjacency_list and dictionary of nodes.
            adjacency_list.remove(node);

            // the above optimization will only
            // work in undirected graph.
            
            We have, have to iterate over all the 
            nodes list and remove target node. */

        for (auto n : adjacency_list)
            n.second -> remove(node);

        adjacency_list.erase(node);
        nodes.erase(label);
    }

    public: void removeEdge(string from ,string to) {

        if (not isValidNode(from) or not isValidNode(to))
            return;

        auto fromNode = nodes[from];
        auto toNode = nodes[to];
        adjacency_list[fromNode] -> remove(toNode);
        /* Since its a directed graph, thats why
            we need from and to, other wise we
            would have taken node1 and node2,
            for the same reason, don't do the reverse
            of the above statement.
            ie.. adjacency_list[toNode] -> remove(fromNode); 
            this will be wrong in directed graph.*/
        
    }

    private: void traverseDepthFirst(Node *root, set<Node*> *visited) {
        print(root -> label);
        visited -> insert(root);

        for (auto &node : *adjacency_list[root]) 
        {
            if (not visited -> count(node))
                traverseDepthFirst(node, visited);
        }
        
    }

    public: void traverseDepthFirst(string root) {
        if (not isValidNode(root))
            return;

        traverseDepthFirst(nodes[root], new set<Node*>);
    }

    public: void traverseDepthFirstIterative(string root) {
        if (not isValidNode(root))
            return;

        auto node = nodes[root];

        stack<Node*> stack;
        set<Node*> visited;

        stack.push(node);

        Node *current = nullptr;

        while (not stack.empty()) {
            current = stack.top();stack.pop();

            if (visited.count(current))
                continue;

            // visiting popped node
            print(current -> label);
            visited.insert(current);

            // pushing neighbours in stack
            for (auto neighbour : *adjacency_list[current])
                if (not visited.count(neighbour))
                    stack.push(neighbour);
        }
    }

    public: void traverseBreadthFirst(string root) {
        if (not isValidNode(root))
            return;

        queue<Node*> queue;
        set<Node*> visited;

        queue.push(nodes[root]);

        Node* current = nullptr;

        while (not queue.empty()) {
            current = queue.front(); queue.pop();

            if (visited.count(current))
                continue;

            print(current -> label);
            visited.insert(current);

            for (auto &neighbour: *adjacency_list[current]) {
                if (not visited.count(neighbour))
                    queue.push(neighbour);
            }
        }

    }

    private: void topologicalSort(Node *node, set<Node*> &visited, stack<Node*> &stack) {
        if (visited.count(node))
            return;

        visited.insert(node);

        for (auto &neighbour: *adjacency_list[node])
            topologicalSort(neighbour, visited, stack);

        stack.push(node);
    }

    public: list<string> topologicalSort() {
        stack<Node*> stack;
        set<Node*> visited;

        for (auto node: nodes)
            topologicalSort(node.second, visited, stack);

        list<string> sorted;

        while (not stack.empty()) {
            sorted.push_back(stack.top() -> label);
            stack.pop();
        }

        return sorted;
    }

    private: bool hasCycle(
            Node *node, 
            set<Node*> &all,
            set<Node*> &visiting, 
            set<Node*> &visited) 
    {
        all.erase(node);
        visiting.insert(node);

        for (auto &neighbour: *adjacency_list[node]) {
            if(visited.count(neighbour))
                continue;
            
            if (visiting.count(neighbour))
                return true;
            
            if (hasCycle(neighbour, all, visiting, visited))
                return true;
        }

        visiting.erase(node);
        visited.insert(node);

        return false;
    }

    public: bool hasCycle() {

        set<Node*> allnodes;
        set<Node*> visiting;
        set<Node*> visited;

        for (auto node: nodes)
            allnodes.insert(node.second);

        auto current = allnodes.begin();

        while (not allnodes.empty()) {
            if (hasCycle(*current, allnodes, visiting, visited))
                return true;

            current++;
        }

        return false;
    }
 
};



int main()
{
    Directed_Graph directed_graph;
    directed_graph.addNode("A");
    directed_graph.addNode("B");
    directed_graph.addNode("C");
    directed_graph.addNode("D");

    directed_graph.addEdge("A", "B");
    directed_graph.addEdge("B", "D");
    directed_graph.addEdge("D", "C");
    directed_graph.addEdge("A", "C");

    // directed_graph.traverseDepthFirst("A");
    // print("\nIterative:");
    // directed_graph.traverseDepthFirstIterative("A");

    // print("\nBFS:");
    // directed_graph.traverseBreadthFirst("K");

    // directed_graph.print_graph();

    Directed_Graph dgraph;
    dgraph.addNode("X");
    dgraph.addNode("A");
    dgraph.addNode("B");
    dgraph.addNode("P");
    dgraph.addEdge("X", "A");
    dgraph.addEdge("X", "B");
    dgraph.addEdge("A", "P");
    dgraph.addEdge("B", "P");

    // auto list = dgraph.topologicalSort();
    // for (auto &&node : list)
    //     print(node);


    Directed_Graph graph2;
    graph2.addNode("A");
    graph2.addNode("B");
    graph2.addNode("C");
    graph2.addEdge("A", "B");
    graph2.addEdge("B", "C");
    graph2.addEdge("C", "A");
    print(graph2.hasCycle());

    print();

    return 0;
}

/* wordings : this expression is a little bit too busy. */