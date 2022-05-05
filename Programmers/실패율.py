def solution(N, stages):
    answer = []
    dic = {i:0 for i in range(1,N+1)}
    for s in stages:
        if s in dic:
            dic[s]+=1
    total=len(stages)
    for key,val in dic.items():
        if total>0:
            dic[key]=val/total
            total=total-val
    sorted_dict = sorted(dic.items(), key = lambda item: item[1],reverse=True)
    for key,value in sorted_dict:
        answer.append(key)
    return answer