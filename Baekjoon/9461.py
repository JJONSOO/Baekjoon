import sys


t = int(input())

p = []
p.append(0)
p.append(1)
p.append(1)
p.append(1)
p.append(2)
p.append(2)

for idx in range(6,101):
        p.append(p[idx-1]+p[idx-5])
for _ in range(t):
    print(p[int(input())])