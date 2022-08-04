import sys
k, n = map(int,input().split())
arr = [int(sys.stdin.readline()) for _ in range(k)]
start , end = 1 , max(arr)
ans =0
while start <= end:
    mid = (end + start)//2
    s = 0
    for a in arr:
        s+=(a//mid)
    if s >= n:
        start=mid+1
    else:
        end=mid-1
print(end)
