from collections import defaultdict
from itertools import permutations
from tkinter import Y
from itertools import combinations


def solution(orders, course):
    total=defaultdict(list)
    answer = []


    for order in orders:
        tmp=[]
        for a in order:
            tmp.append(a)
        for c in course:
            b=list(combinations(tmp,c))
            y=""
            for x in b:
                for idx in range(c):
                    y+=x[idx]
                # print(y)
                y=''.join(sorted(y))
                total[y].append('1')
                y=""
    # print(total)
    for c in course:
        max=int(0)

        for t in total:
            if len(t)>=c and len(total[t])>=max:
                if(max<len(total[t])):
                    max=len(total[t])
        if max >=2:
            for t in total:
                if len(total[t])==max and len(t)>=c:
                    # print(max)
                    # print(t)
                    # print(len(t))
                    # print(c)
                    # print(len(t)>=c)
                    answer.append(t)
        # print('끝')
    answer=set(answer)
    answer = list(answer)
    # print(answer)
    # answer=answer.sort()
    return sorted(answer)