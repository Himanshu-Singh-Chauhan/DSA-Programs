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
        index = self.hash(key)
        if self.entries[index] is None:
            self.entries[index] = [] # Used lists in place of linked list.

        for entry in self.entries[index]:
            if entry.key == key:
                entry.value = value
                return

        self.entries[index].append(self.KeyValue(key, value))

    
    def get(self, key):
        index = self.hash(key)
        bucket = self.entries[index]

        if bucket is not None:
            for entry in bucket:
                if entry.key == key:
                    return entry.value

        return None

    
    def remove(self, key):
        index = self.hash(key)
        bucket = self.entries[index]
        if bucket is None:
            # ----
            print("Key does not exists")
            return None
            # ----

        for entry in bucket:
            if entry.key == key:
                bucket.remove(entry)
                return

        # ----
        print("Key does not exists")
        return None
        # ----



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