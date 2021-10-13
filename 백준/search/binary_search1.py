import random

def binary_search(data, search):
    if len(data) == 1 and data[0] == search:
        return True
    if len(data) == 1 and data[0] != search:
        return False
    if len(data) == 0:
        return False
    
    middle = len(data) // 2
    
    if data[middle] == search:
        return True
    else:
        if data[middle] > search:
            return binary_search(data[:middle], search)
        else:
            return binary_search(data[middle:], search)
        
data_list = random.sample(range(100), 10)
data_list.sort()

print(data_list)
print(binary_search(data_list, 10))
