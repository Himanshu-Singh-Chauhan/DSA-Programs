numbers = [10,2,30,4,5,110,11,24,45,76,90,6,8 ] 

for i in range(len(numbers)): 
    min_idx = i 
    for j in range(i+1, len(numbers)): 
        if numbers[min_idx] > numbers[j]: 
            min_idx = j 
    numbers[i], numbers[min_idx] = numbers[min_idx], numbers[i] 
  
print(numbers)