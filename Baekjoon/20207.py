from operator import le


N = int(input())
calendar = [0 for _ in range(1000)]
for _ in range(N):
    start, end = map(int,input().split())
    for idx in range(start,end+1):
        calendar[idx]+=1
width , length = 0, 0
ans = 0
for idx in range(1000):
    if calendar[idx]!=0:
        length+=1
        width = max(width,calendar[idx])
    else:
        if width > 0:
            ans += width*length
        width , length = 0, 0
        
print(ans)