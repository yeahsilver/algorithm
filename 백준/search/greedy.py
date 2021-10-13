def min_coin(value, coin_list):
    coin_list.sort(reverse = True)
    result = []
    cnt = 0
    
    for coin in coin_list:
        coin_num = value // coin
        cnt +=coin_num
        value -= coin_num * coin
        result.append([coin, coin_num])
    
    return result
        
    
coin_list = [500, 100, 50, 1]
min_coin(4720, coin_list)
