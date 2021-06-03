from sys import stdin

start, end, streaming = map(str, input().split())

start = int("".join(start.split(":")))
end = int("".join(end.split(":")))
streaming = int("".join(streaming.split(":")))

chatting = {}

count = 0

while(True):
    line = stdin.readline()
    if len(line) < 5: break
    t, _id = map(str, line.split())
    t = int("".join(t.split(":")))
    
    if t <= start:
        chatting[_id] = 1
        
    elif end <= t <= streaming:
        if(chatting.get(_id)) == 1:
            chatting[_id] += 1
            count+=1   
print(count)    
    
