import sys
sys.setrecursionlimit(10 ** 8)
input = sys.stdin.readline

M,N= map(int,input().split())
arr=[list(map(int,input().split()))for _ in range(M)]
dp=[[-1]*N for _ in range(M)]
dx,dy = [1,-1,0,0],[0,0,1,-1]
ans = 0
def dfs(x,y):
    if x==M-1 and y==N-1:
        return 1
    if dp[x][y]!=-1:
        return dp[x][y]
    ways=0
    for idx in range(4):
        if(-1<x+dx[idx]<M and -1<y+dy[idx]<N) and arr[x+dx[idx]][y+dy[idx]]<arr[x][y]:
            ways+=dfs(x+dx[idx],y+dy[idx])
    dp[x][y]=ways
    return ways
print(dfs(0,0))