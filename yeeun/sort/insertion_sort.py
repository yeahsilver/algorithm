import random 
data = random.sample(range(10),5)
for index in range(len(data)-1):
    for index2 in range(index+1, 0, -1):
        if data[index2] < data[index2 - 1]:
            data[index2], data[index2 - 1] = data[index2 - 1], data[index2]
        else:
            break 
            # data[index2] >= data[index - 1]이면 더 앞을 비교 할 필요가 없기 때문에.
print(data)
