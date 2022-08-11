import sys


N = int(input())
liquids= list(map(int,input().split()))
start , end = 0 , len(liquids)-1
ans = sys.maxsize
x,y=-1,-1
while start < end :
    s = liquids[end]+liquids[start]
    if abs(liquids[end]+liquids[start]) < ans:
        ans=abs(liquids[end]+liquids[start])
        x,y=liquids[start],liquids[end]
    if s>0:
        end-=1
    elif  s<0:
        start+=1
    else:
        break
print(x,y)
    