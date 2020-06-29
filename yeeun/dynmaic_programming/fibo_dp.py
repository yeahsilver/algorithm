def fibo_dp(n):
    cache = [0 for index in range(n + 1)] # 인덱스 할당 0~n까지의 길이를 갖는 배열 생성.
    cache[0] = 0
    cache[1] = 1
    
    for index in range(2, n + 1):
        cache[index] = cache[index-1] + cache[index-2]
        
    return cache[n]

print(fibo_dp(10))
