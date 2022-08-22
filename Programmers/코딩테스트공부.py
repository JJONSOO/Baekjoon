def solution(alp, cop, problems):
    arr=[[1000 for _ in range(500)] for _ in range(500)]
    arr[alp][cop]=0
    m_alp, m_cop = max(problems,key=lambda item:item[0])[0],max(problems,key=lambda item:item[1])[1]
    m_alp, m_cop = max(m_alp,alp) , max(m_cop,cop)

    for x in range(alp,m_alp+1):
        for y in range(cop,m_cop+1):
            arr[x+1][y]=min(arr[x][y]+1,arr[x+1][y])
            arr[x][y+1]=min(arr[x][y]+1,arr[x][y+1])
            for problem in problems:
                alp_req, cop_req , alp_rwd, cop_rwd, cost = problem[0],problem[1],problem[2],problem[3],problem[4]
                if x >= alp_req and y >= cop_req:
                    arr[min(m_alp,x+alp_rwd)][min(m_cop,y+cop_rwd)]=min(arr[x][y]+cost,arr[min(m_alp,x+alp_rwd)][min(m_cop,y+cop_rwd)])

    return arr[m_alp][m_cop]