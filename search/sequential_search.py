import random

def sequential(data, search):
    for index in range (len(data)):
        if data[index] == search:
            return index
    return -1

data_list = random.sample(range(100), 10)

print(data_list)
print(sequential(data_list, 10))
