# import sys
# from tokenize import String; input = sys.stdin.readline
# N , M  = map(int , input().split())

# visited = [[0 for _ in range(M)] for _ in range(N)]
# d = {
#     'L': [0, -1],
#     'R': [0, 1],
#     'U': [-1, 0],
#     'D': [1, 0]
# }
# ans =0
# g = [list(input()) for _ in range(N)]
# print(g)
# for i in range(N):
#     for j in range(M):
#         if visited[i][j]!='0':
#             x,y=i,j
#             ans +=1
#             while visited[x][y]!='0':
#                 print('x,y ',x,y)
#                 visited[x][y]='0'
#                 x,y=d[g[x][y]][0],d[g[x][y]][1]
                

#             print('end')
#             print(visited)

# print(ans)
n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]
visited = [[0] * m for _ in range(n)]
d = {
    'L': [0, -1],
    'R': [0, 1],
    'U': [-1, 0],
    'D': [1, 0]
}
count, ans = 0, 0

def dfs(x, y, c):
    global ans
    if visited[x][y]:
        if visited[x][y] == c:
            ans += 1
        return

    visited[x][y] = c
    nx, ny = x + d[board[x][y]][0], y + d[board[x][y]][1]
    dfs(nx, ny, c)

for i in range(n):
    for j in range(m):
        if not visited[i][j]:
            count += 1
            dfs(i, j, count)

print(ans)