def solution(s):
    answer = []
    s=s[2:-2].split("},{")
    l=[]
    for a in s:
        tmp=[]
        for idx in range(len(a.split(","))):
            tmp.append(int(a.split(",")[idx]))
        l.append(tmp)
    l=sorted(l,key = lambda x : len(x))
    for a in l:
        for b in a:
            if b not in answer:
                answer.append(b)
    return answer