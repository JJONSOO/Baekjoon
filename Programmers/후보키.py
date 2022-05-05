import itertools
from re import U
from unittest import result

from numpy import result_type, true_divide


def solution(relation):
    answer = []
    uu =0
    ll =[]
    for i in range(0,len(relation[0])):
        tmp=[]
        for j in range(0,len(relation)):
            tmp.append(relation[j][i])
        if len(tmp) == len(set(tmp)):
            uu+=1
        else:
            ll.append(tmp)

    for i in range(2,len(ll)+1):
        tmp=[]
        for j in range(1,len(ll)+1):
            tmp.append((j))
        result=list(itertools.combinations(tmp,i))

        for y in result:
            tmp= ['' for _ in range(len(relation))]
            for z in y:
                for u in range(len(relation)):
                    tmp[u]+=ll[z-1][u]+','
            print(tmp)
            if len(tmp) == len(set(tmp)):
                ck=True
                for qq in answer:                    
                    if len(list(set(qq) & set(y)))>0:
                        tt=sorted(list(set(qq) & set(y)))
                        if tt in answer:
                            ck=False
                            break
                if ck:

                    y=sorted(list(y))
                    answer.append(y)

    return len(answer)+uu