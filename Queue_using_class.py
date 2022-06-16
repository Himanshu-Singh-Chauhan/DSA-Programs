class Queue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [None for i in range(capacity)]
        self.rear = 0
        self.front = 0
        self.count = 0

    def enqueue(self, item):
        if self.count == len(self.queue):
            print(f"Queue Full, can't enqueue : {item}")
            return
        self.queue[self.rear] = item
        self.rear = (self.rear + 1) % len(self.queue)
        self.count += 1

    def dequeue(self):
        if self.count == 0:
            print("Queue Empty")
            return 
        item = self.queue[self.front]
        self.queue[self.front] = None
        self.front = (self.front + 1) % len(self.queue)
        self.count -= 1
        return item
        
    def toArray(self):
        array = []
        counter = self.front
        for _ in range(self.count):
            array.append(self.queue[counter])
            counter = (counter + 1) % len(self.queue)
        return array

queue = Queue(5)
queue.enqueue(10) 
queue.enqueue(20) 
queue.enqueue(30) 
queue.enqueue(40) 
queue.enqueue(50) 
queue.dequeue()
queue.dequeue()
queue.enqueue(60) 
queue.enqueue(70) 
queue.enqueue(80) 
queue.dequeue()
queue.enqueue(90) 
queue.enqueue(100) 
print(queue.toArray())