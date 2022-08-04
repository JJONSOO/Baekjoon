n = int(input())
arr = []
dp = [0 for i in range(n)]
for _ in range(n):
    arr.append(int(input()))
cnt=0
# dp[0]=1 
for i in range(1,n):
    dp[i]=1
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i]=max(dp[i],dp[j]+1)
print(n-max(dp))