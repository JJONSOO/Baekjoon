from itertools import combinations, permutations


N = int(input())
sauce = []
for _ in range(N):
    s, b = map(int,input().split())
    sauce.append([s,b])
ans  = 9999999
for length in range(len(sauce),0,-1):
    tmp=list(combinations(sauce,length))
    for i in range(len(tmp)):
        s,b=1,0
        for j in range(len(tmp[i])):
            s*=tmp[i][j][0]
            b+=tmp[i][j][1]
        ans=min(ans,abs(s-b))
print(ans)