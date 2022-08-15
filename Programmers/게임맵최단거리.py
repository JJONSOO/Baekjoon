from collections import deque


def solution(maps):
    answer = 99999999
    queue = deque()
    queue.append([0,0,1])
    visited = [[False for _ in range(len(maps[0]))] for _ in range(len(maps))]
    visited[0][0]=True
    dx, dy = [1,-1,0,0], [0,0,1,-1]
    while queue:
        lst = queue.popleft()
        _x,_y,cnt =lst[0],lst[1],lst[2]
        if _x==len(maps[0])-1 and _y==len(maps)-1:
            if cnt < answer:
                answer = cnt
        else:
            for i in range(4):
                x,y = _x+dx[i], _y+dy[i]
                if -1<x<len(maps[0]) and -1<y<len(maps) and visited[y][x]==False and maps[y][x]==1:
                    queue.append([x,y,cnt+1])
                    visited[y][x]=True
    if answer==99999999:
        return -1
    return answer