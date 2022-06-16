class Stack:
    def __init__(self, capacity):
        self.stack = [None for i in range(capacity)]
        self.length = 0
        self.capacity = capacity

    def push(self, item):
        if self.length == self.capacity:
            print("STACK OVERFLOW!")
            return -1
        self.stack[self.length] = item
        self.length += 1

    def pop(self):
        if self.length == 0:
            print("STACK UNDERFLOW!")
            return -1
        self.length -= 1
        return self.stack[self.length]

    def peek(self):
        if self.length == 0:
            print("STACK EMPTY")
            return -1
        return self.stack[self.length - 1]

    def isEmpty(self):
        return self.length == 0

    def getStack(self):
        return self.stack[0:self.length]

    
stack = Stack(5)
stack.push(10)
stack.push(20)
stack.push(30)
print(f"Stack as array : {stack.getStack()}")
print(f"top item : {stack.peek()}")
print(f"popped element : {stack.pop()}")
print(f"Stack as array : {stack.getStack()}")