recursiveCount = -1
def quickSort(array, start, end):
    global recursiveCount
    recursiveCount += 1
    if (start >= end) :
        return
    boundary = partition(array, start, end)
    quickSort(array, start, boundary - 1)
    quickSort(array, boundary + 1, end)
    
def partition(array, start, end) :
    pivot = array[end]
    boundary = start - 1
    for i in range(start, end + 1) :
        if (array[i] <= pivot) :
            boundary += 1
            array[i], array[boundary] = array[boundary], array[i]
    return boundary

# numbers = [10, 2, 30, 4, 5, 110, 11, 24, 45, 76, 90, 6, 8 ]
numbers = [2, 1, 3, 4, 5, 5, 6]
quickSort(numbers, 0, len(numbers) - 1)
print(numbers)
print(f"Recursive calls : {recursiveCount}")