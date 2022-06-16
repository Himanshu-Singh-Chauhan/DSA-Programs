def insertionSort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i-1
        while j >= 0 and key < array[j] :
                array[j + 1] = array[j]
                j -= 1
        array[j + 1] = key
 
 
array = [10,2,30,4,5,110,11,24,45,76,90,6,8 ]
insertionSort(array)
print(array)