# This is Binary Search Tree where left child is smaller than right
# and NOT Binary Tree.

class BinarySearchTree:
# ----------------------------------------
    class Node:
        def __init__(self, value):
            self.value = value
            self.leftChild = None
            self.rightChild = None
# ----------------------------------------
    def __init__(self):
        self.root = None
        self.inOrderTraverse = []
        self.preOrderTraverse = []
        self.postOrderTraverse = []
# ----------------------------------------
    def insert(self, value):
        node = self.Node(value)

        if self.root == None:
            self.root = node
            return
        
        current  = self.root
        while True:
            if value < current.value:
                if current.leftChild is None:
                    current.leftChild = node
                    break
                current = current.leftChild
            else:
                if current.rightChild is None:
                    current.rightChild = node
                    break
                current = current.rightChild
# ----------------------------------------
    def remove(self, value):
        self.__remove(self.root, value)
        print(f"Deleted {value}")
# ----------------------------------------
    def __remove(self, root, value):
        if root is None:
            return root
        
        if value < root.value:
            root.leftChild = self.__remove(root.leftChild, value)
        elif value > root.value:
            root.rightChild = self.__remove(root.rightChild, value)
        else:
            if root.leftChild is None:
                rightChild = root.rightChild
                root = None
                return rightChild
            elif root.rightChild is None:
                leftChild = root.leftChild
                root = None
                return leftChild
            
            rightChildLeaf = self.minValueNode(root.rightChild)
            root.value = rightChildLeaf.value
            root.rightChild = self.__remove(root.rightChild, rightChildLeaf.value)
        return root
# ----------------------------------------
    def minValueNode(self, root):
        current = root
        while(current.leftChild is not None):
            current = current.leftChild
        return current
# ----------------------------------------
    def find(self, value):
        current = self.root
        while current is not None:
            if value < current.value:
                current = current.leftChild
            elif value > current.value:
                current = current.rightChild
            else:
                return True
        return False
# ----------------------------------------
    def traversePreOrder(self):
        self.__traversePreOrder(self.root)
        print("Pre Order : ", self.preOrderTraverse)
        self.preOrderTraverse = []
# ----------------------------------------
    def __traversePreOrder(self, root):
        if root is None:
            return
        self.preOrderTraverse.append(root.value)
        self.__traversePreOrder(root.leftChild)
        self.__traversePreOrder(root.rightChild)
# ----------------------------------------
    def traverseInOrder(self):
        self.__traverseInOrder(self.root)
        print("In Order : ", self.inOrderTraverse)
        self.inOrderTraverse = []
# ----------------------------------------
    def __traverseInOrder(self, root):
        if root is None:
            return
        self.__traverseInOrder(root.leftChild)
        self.inOrderTraverse.append(root.value)

        self.__traverseInOrder(root.rightChild)
# ----------------------------------------
    def traversePostOrder(self):
        self.__traversePostOrder(self.root)
        print("Post Order : ", self.postOrderTraverse)
        self.postOrderTraverse = []
# ----------------------------------------
    def __traversePostOrder(self, root):
        if root is None:
            return
        self.__traversePostOrder(root.leftChild)
        self.__traversePostOrder(root.rightChild)
        self.postOrderTraverse.append(root.value)
# ----------------------------------------
    def traverseLevelOrder(self):
        for i in range(self.height()):
            for value in self.nodesAtDistance(i):
                print(value)
# ----------------------------------------
    def height(self):
        if self.root == None:
            return -1
        return self.__height(self.root)
# ----------------------------------------
    def __height(self, root):
        if self.isLeaf(root):
            return 0
        return 1 + max(self.__height(root.leftChild), self.__height(root.rightChild))
# ----------------------------------------
    def isLeaf(self, leaf):
        return leaf.leftChild is None and leaf.rightChild is None
# ----------------------------------------
    def nodesAtDistance(self, distance):
        List = []
        self.__nodesAtDistance(self.root, distance, List)
        return List
# ----------------------------------------
    def __nodesAtDistance(self, root, distance, List):
        if root is None:
            return

        if distance == 0:
            List.append(root.value)
            return

        self.__nodesAtDistance(root.leftChild, distance-1, List)
        self.__nodesAtDistance(root.rightChild, distance-1, List)

        return 

        



# numbers = [10, 22, 3, 40, 55, 7, 10, 76, 87, 56, 34, 23, 9, 66 ]
# numbers = [50, 30, 20, 40, 70, 60, 80]
numbers = [30, 20, 15, 5, 18, 25, 40, 35, 50, 45, 60]
# numbers = []

tree = BinarySearchTree()
for _ in numbers: tree.insert(_)


# tree.traverseInOrder()
# tree.traversePreOrder()
# tree.traversePostOrder()
# tree.remove(20)
# tree.remove(30)
# tree.remove(50)
# print(tree.find(55))

# print(tree.height())

tree.traverseLevelOrder()
print(tree.nodesAtDistance(2))
