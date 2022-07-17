from sys import stdin
input = stdin.readline
import sys
sys.setrecursionlimit(200000)

n , m = map(int,input().split())
parent=[i for i in range(n)]

def find_parent(parent, x):
    if parent[x] !=x :
        parent[x]=find_parent(parent,parent[x])
    return parent[x]
def union_parent(parent,a,b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)
    if a<b:
        parent[b]=a
    else:
        parent[a]=b

ans =0
for idx in range(m):
    a , b = map(int ,input().split())
    if find_parent(parent,a) == find_parent(parent,b):
        ans = idx +1
        break
    else:
        union_parent(parent,a,b)
print(ans)