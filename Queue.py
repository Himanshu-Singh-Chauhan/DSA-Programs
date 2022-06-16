class Queue:
    def __init__(self, capacity):
        self.queue = [None for i in range(capacity)]
        self.rear = 0
        self.length = 0
        self.front = 0
        self.capacity = capacity

    def reverseQueue(self):
        stack = Stack(self.length)
        while (not self.isEmpty()):
            stack.push(self.remove())
        while(not stack.isEmpty()):
            self.add(stack.pop())

    def enqueue(self, item):
        if self.length == self.capacity:
            print("QUEUE FULL")
            return -1
        self.queue[self.rear] = item
        self.rear += 1
        self.length += 1

    def dequeue(self):
        item = self.queue[self.front]
        self.queue[self.front] = None
        self.front += 1
        self.length -= 1
        return item

    def getQueue(self):
        return self.queue[0:self.length]
