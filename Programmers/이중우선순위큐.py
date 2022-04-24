import heapq
def solution(operations):
    answer = []
    for i in range(len(operations)):
        if operations[i][0]=='I':
            heapq.heappush(answer,int(operations[i][2:]))
        elif(len(answer)>0):
            if operations[i][2]=='-':
                heapq.heappop(answer)
            else:
                del answer[answer.index(max(answer))]
    if(len(answer))==0:
        return [0,0]
    else:
        return [max(answer),answer[0]]

    # return answer