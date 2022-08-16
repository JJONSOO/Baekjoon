from collections import deque


def solution(info, edges):
    g=[[] for _ in range(len(info)+1)]
        
    for edge in edges:
        g[edge[0]].append(edge[1])
        g[edge[1]].append(edge[0])
    q=deque()
    ans = 0
    
    # 현재 node , sheep , wolf , visited 
    q.append([1,0,[0]])
    while q:
        lst = q.popleft()
        sheep , wolf , visited = lst[0], lst[1], lst[2]
        if sheep > ans : 
            ans = sheep
        for v in visited:
            for n_node in g[v]:
                if n_node not in visited:
                    # 늑대
                    if info[n_node]==1:
                        if sheep -1 >wolf :
                            q.append([sheep,wolf+1,visited+[n_node]])
                    else:
                            q.append([sheep+1,wolf,visited+[n_node]])
    return ans