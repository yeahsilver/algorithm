def func(n):
    print(n)
    if n ==1:
        return n
    elif n%2 == 1:
        return func((3*n)+1)
    else:
        return func(int(n/2))

func(10)
