from collections import defaultdict
from heapq import heappop, heappush


def solution(n, paths, gates, summits):
    summits.sort()
    summits_set = set(summits)
    graph = [[] for _ in range(n+1)]
    for i, j, w in paths:
        graph[i].append((w, j))
        graph[j].append((w, i))
        
    q = []  
    visited = [10000001] * (n + 1)

    for gate in gates:
        heappush(q, (0, gate))
        visited[gate] = 0

    while q:
        intensity, node = heappop(q)
        if node in summits_set or intensity > visited[node]:
            continue
        
        for weight, next_node in graph[node]:
            new_intensity = max(intensity, weight)
            if new_intensity < visited[next_node]:
                visited[next_node] = new_intensity
                heappush(q, (new_intensity, next_node))
    min_intensity = [0, 10000001]
    for summit in summits:
        if visited[summit] < min_intensity[1]:
            min_intensity[0] = summit
            min_intensity[1] = visited[summit]

    return min_intensity