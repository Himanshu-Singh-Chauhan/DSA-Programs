def bubbleSort(array):
    isSorted = False
    loopCount = 0
    for i in range(len(array)) :
        isSorted = True
        loopCount += 1
        for j in range(1, len(array) - i) :
            loopCount += 1
            if array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]
                isSorted = False
        if isSorted:
            return loopCount
    return loopCount

numbers = [10, 2, 30, 4, 5, 110, 11, 24, 45, 76, 90, 6, 8]
# numbers = [2, 1, 3, 4, 5, 5, 6]
# numbers = [6, 5, 4, 3, 2, 5, 1]
loopCount = bubbleSort(numbers)
print(numbers)
print(f"loop count : {loopCount}")