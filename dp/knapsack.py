data_list = [(10, 10), (15, 12), (20, 10), (25, 8), (30, 5)]

def fractional_knapsack(data_list, capacity):
    data_list = sorted(data_list, key=lambda x: x[1]/x[0], reverse = True)
    result = []
    total = 0
    
    for data in data_list:
        if capacity - data[0] >= 0:
            capacity -= data[0]
            total += data[1]
            result.append([data[0], data[1], 1])
        else:
            fraction = capacity / data[0]
            total += data[1] * fraction
            result.append([data[0], data[1], fraction])
            break
            
    return total, result

def zero_one_knapsack(data_list, capacity):
    data_list = sorted(data_list, key=lambda x: x[1]/x[0], reverse = True)
    result = []
    total = 0
    
    for data in data_list:
        if capacity - data[0] >= 0:
            capacity -= data[0]
            total += data[1]
            result.append([data[0], data[1], 1])
        else:
            break
            
    return total, result

print(fractional_knapsack(data_list, 30))

print(zero_one_knapsack(data_list, 30))

            
