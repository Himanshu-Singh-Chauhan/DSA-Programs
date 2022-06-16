# Python's Lists basically works like linked lists
# So to avoid dependency on linked list, I used just lists.
# You can replace it with linked list if you want.

# put(key, value)
# get(key) : returns value
# remove(key) : removes corresponding value from hash table
# key: int // does not matter in python
# value: strings // does not matter in python
# collisions: chaining (linked lists)

class HashTable:
    class KeyValue:
        def __init__(self, key, value) -> None:
            self.key = key
            self.value = value


    def __init__(self) -> None:
        self.entries = [None for _ in range(5)] # keeping it fixed like arrays, for simplicity
        self.len_of_entries = len(self.entries) # to keep track of size of entries

    def put(self, key, value):
        entry = self.getEntry(key)
        if entry is not None:
            entry.value = value
            return
        
        self.getOrCreateBucket(key).append(self.KeyValue(key, value))

    
    def get(self, key):
        entry = self.getEntry(key)
        return entry.value if entry != None else None

    
    def remove(self, key):
        entry = self.getEntry(key)
        if entry is None:
            # ----
            print("Key does not exists")
            return None
            # ----

        self.getBucket(key).remove(entry)


    def getBucket(self, key):
        return self.entries[self.hash(key)]


    def getOrCreateBucket(self, key):
        index = self.hash(key)
        bucket = self.entries[index]

        if bucket is None:
            # we cannot just set bucket to new linked list
            # as it will just initialise the local variable bucket
            # we need to actually use the index to access it or modify it
            self.entries[index] = [] # Used lists in place of linked list.
            bucket = self.entries[index] # we need to re-assign it as we only -
            # - updated at the index and local bucket is still None

        return bucket

    def getEntry(self, key):
        bucket = self.getBucket(key)
        if bucket is not None:
            for entry in bucket:
                if entry.key == key:
                    return entry

        return None


    def hash(self, key):
        # assuming all keys are positive
        return key % self.len_of_entries



table = HashTable()
table.put(6, "A")
table.put(8, "B")
table.put(11, "C")
table.put(6, "A+")
table.remove(60)
print(table.get(8))