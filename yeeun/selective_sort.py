import random 
data = random.sample(range(10),5)
for stand in range(len(data)):
    lowest = stand
    for index in range(stand + 1, len(data)):
        if data[lowest] > data[index]:
            data[lowest], data[index] = data[index], data[lowest]
print(data)
