class LinkedList:

    # ----------------------------------------
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None
            self.prev = None
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
            self.node.prev = self.last  # Double
            self.last = self.node

        self.size = self.size + 1
# ----------------------------------------

    def addFirst(self, data):
        self.node = self.Node(data)

        if self._isEmpty():
            self.first = self.last = self.node
        else:
            self.node.next = self.first
            self.first.prev = self.node
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
            self.node.prev = after_node  # Double
            self.node.next = Next
            Next.prev = self.node  # Double

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
        self.first.prev = None  # Double

        self.size = self.size - 1
# ----------------------------------------

    def removeLast(self):
        if self._isEmpty():
            return False

        if (self.first == self.last):
            self.first = self.last = None
            return

        previous = self.last.prev  # Performance advantage of Double.
        self.last = previous
        # now last is previous, so next line is equivalent to previous.next = None
        self.last.next = None
        self.last.prev = previous.prev  # Double

        self.size = self.size - 1
# ----------------------------------------

    def Size(self):
        return self.size
# ----------------------------------------

    def _isEmpty(self):
        return self.first is None
# ----------------------------------------

    def contains(self, data):
        return self.indexOf(data) != -1
# ----------------------------------------

    def toArray(self):
        array = []
        current = self.first
        while(current != None):
            array.append(current.data)
            current = current.next
        return array


mylist = LinkedList()
mylist.addFirst(10)
mylist.addFirst(10)
mylist.addLast(20)
mylist.addLast(30)
mylist.addMiddle(100, 10)
array = mylist.toArray()

print(array)