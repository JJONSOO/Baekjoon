
from collections import deque

N = int(input())
arr = [0 for _ in range(N)]
t = list(map(int,input().split()))
q = deque()
q.append([t[len(t)-1],len(t)-1])
for i in range(1,N+1):
    while len(q)>0 and q[0][0] < t[len(t)-i]:
        arr[q[0][1]]=len(t)-i + 1
        q.popleft()
    q.appendleft([t[len(t)-i],len(t)-i])
for a in arr:
    print(a,end=' ')