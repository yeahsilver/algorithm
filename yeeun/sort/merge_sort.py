import random
def mergesplit(data):
    # 길이가 1 이하이면 데이터 반환
    if len(data) <= 1:
        return data

    # 아니면 right / left 반반 나누기 -> merge(right, left) 수행
    middle = int(len(data)/2)
    left = mergesplit(data[:middle])
    right = mergesplit(data[middle:])
    
    print(left, right)
    
    return merge(left, right)

    
def merge(left, right):
    merged = []
    left_point, right_point = 0, 0
    
    # case 1: right / left 둘다 남았을 경우
    while len(left) > left_point and len(right) > right_point:
        if left[left_point] > right[right_point]:
            merged.append(right[right_point])
            right_point+= 1
        else:
            merged.append(left[left_point])
            left_point += 1
            
    # case 2: left만 남았을 경우
    while len(left) > left_point:
        merged.append(left[left_point])
        left_point += 1
       
    # case 3: right만 남았을 경우
    while len(right) > right_point:
        merged.append(right[right_point])
        right_point+= 1
    
    return merged

data_list = random.sample(range(100), 10)
print(mergesplit(data_list))
