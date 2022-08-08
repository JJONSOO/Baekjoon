from collections import deque
from operator import contains
import sys 
sys.setrecursionlimit(10**9)

N, K = map(int,input().split())

d_check = [False for _ in range(200000 + 1)]
d=deque()

def bfs(now):
    ans_cnt=0
    ans_time=-1
    d_check[now]=True
    d.append((N,0))
    if N==0:
        d.append((N+1,1))
    while d:
        now,cnt = d.popleft()
        d_check[now]=True
        if now == K:
            if ans_time==-1:
                ans_time=cnt
            if ans_time == cnt:
                ans_cnt+=1
                continue

        if 0 < now <=100000:
            if d_check[now+1]==False:
                d.append((now+1,cnt+1))
            if d_check[now-1]==False:
                d.append((now-1,cnt+1))
            if d_check[now*2]==False:
                d.append((now*2,cnt+1))
    return ans_time,ans_cnt
ans_time,ans_cnt=bfs(N)

print(ans_time)
print(ans_cnt)