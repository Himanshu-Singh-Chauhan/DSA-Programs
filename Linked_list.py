class LinkedList:

# ----------------------------------------
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None
# ----------------------------------------

    def __init__(self):
        self.first = None
        self.last = None
        self.size = 0
# ----------------------------------------

    def addLast(self, data):
        self.node = self.Node(data)

        if self.first == None:
            self.first = self.last = self.node
        else:
            self.last.next = self.node
            self.last = self.node

        self.size = self.size + 1
# ----------------------------------------

    def addFirst(self, data):
        self.node = self.Node(data)

        if self._isEmpty():
            self.first = self.last = self.node
        else:
            self.node.next = self.first
            self.first = self.node

        self.size = self.size + 1
# ----------------------------------------

    def addMiddle(self, data, after_node):
        current = self.first
        while(current is not None):
            if (current.data == after_node):
                after_node = current
                break
            current = current.next

        Next = after_node.next

        self.node = self.Node(data)

        if self._isEmpty():
            self.first = self.last = self.node
        else:
            after_node.next = self.node
            self.node.next = Next

        self.size = self.size + 1
# ----------------------------------------

    def indexOf(self, data):
        index = 0
        current = self.first

        while(current is not None):
            if (current.data == data):
                return index
            current = current.next
            index = index + 1

        return -1
# ----------------------------------------

    def removeFirst(self):
        if self._isEmpty():
            return False

        if self.first == self.last:
            self.first = self.last = None
            return

        second = self.first.next
        self.first.next = None  # Remove the link, cleanup.
        self.first = second

        self.size = self.size - 1
# ----------------------------------------

    def removeLast(self):
        if self._isEmpty():
            return False

        if (self.first == self.last):
            self.first = self.last = None
            return

        previous = self.getPrevious(self.last)
        self.last = previous
        # now last is previous, so next line is equivalent to previous.next = None
        self.last.next = None

        self.size = self.size - 1
# ----------------------------------------

    def Size(self):
        return self.size
# ----------------------------------------

    def getPrevious(self, node):
        current = self.first

        while(current != None):
            if (current.next == node):
                return current
            current = current.next

        return None
# ----------------------------------------

    def _isEmpty(self):
        return self.first is None
# ----------------------------------------

    def toArray(self):
        array = []
        current = self.first
        while(current != None):
            array.append(current.data)
            current = current.next
        return array
# ----------------------------------------

    def _isEmpty(self):
        return self.first is None
# ----------------------------------------

    def contains(self, data):
        return self.indexOf(data) != -1
# ----------------------------------------

    def reverse(self):
        if self._isEmpty():
            return False

        current = self.first.next
        previous = self.first

        while(current != None):
            next = current.next
            current.next = previous
            previous = current
            current = next

        self.last = self.first
        self.last.next = None
        self.first = previous


mylist = LinkedList()
mylist.addFirst(10)
mylist.addLast(20)
mylist.addLast(30)
mylist.addMiddle(100, 10)
mylist.reverse()
array = mylist.toArray()

print(array)
