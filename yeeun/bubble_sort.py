import random

for index in range(5):
    data = random.sample(range(10),5)

for index in range(len(data) - 1):
    for index2 in range(len(data) - index - 1):
        swap = False
        if data[index2] > data[index2 + 1]:
            data[index2], data[index2 + 1] = data[index2 + 1], data[index2]
            swap = True
    if swap == False:
        break
        
print(data)
