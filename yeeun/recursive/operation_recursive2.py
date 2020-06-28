def f(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    elif n ==3:
        return 4
    else :
        return f(n-3) + f(n-2) + f(n-1)

print(f(5))
