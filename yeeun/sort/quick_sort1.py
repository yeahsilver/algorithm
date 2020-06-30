import random 

def qsort(data):
    if len(data) <= 1:
        return data
    
    left = []
    right = []
    pivot = data[0]
    
    for index in range(1, len(data)):
        if pivot > data[index]:
            left.append(data[index])
        else:
            right.append(data[index])
    
    return qsort(left) + [pivot] + qsort(right)

data_list = random.sample(range(100), 10)

print(qsort(data_list))
