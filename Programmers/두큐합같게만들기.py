def solution(queue1, queue2):
    s = (sum(queue1)+sum(queue2))/2
    start , end = 0, 0
    q = queue1+ queue2
    _s = 0
    ans = 1e9
    while True:
        if _s >s:
            _s -= q[start]
            start +=1
        elif _s == s:
            if end - len(queue1)>=0:
                ans=min(ans, start+end-len(queue1))
            else:
                ans=min(ans,start+2*len(queue1)-end)
            _s -= q[start]
            start +=1
        elif end == len(queue1)*2:
            break
        else:
            _s += q[end]
            end+=1
    if ans == 1e9:
        return -1
    else:
        return ans