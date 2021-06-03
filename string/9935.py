string = input()
bomb = input()

len_bomb = len(bomb)


stack = []
for c in string:
    stack.append(c)

    if len(stack) >= len_bomb:
        flag = True

        for i in range(1, 1+len_bomb):
            if(stack[-i] != bomb[-i]):
                flag = False
                break

        if flag:
            for _ in range(len_bomb):
                stack.pop()

if stack:
    print("".join(stack))
else:
    print("FRULA")
    
