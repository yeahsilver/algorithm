def factorial(n): 
    if n > 1:
        return n * factorial(n-1)
    else:
        return n
    
for n in range(5):
    print(factorial(n))
