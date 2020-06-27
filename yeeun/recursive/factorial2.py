def factorial(n): 
    if n <= 1:
        return n
    return_value = n * factorial(n - 1)
    return return_value

for n in range(5):
    print(factorial(n))
