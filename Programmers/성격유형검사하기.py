from collections import defaultdict


def solution(survey, choices):
    answer = ''
    d = defaultdict(int)
    for idx in range(0,len(survey)):
        if choices[idx] <4:
            d[survey[idx][0]]+=4-choices[idx]
        if choices[idx] >4:
            d[survey[idx][1]]+=choices[idx]-4
    mbti=[['R','T'],['C','F'],['J','M'],['A','N']]
    for m in mbti:
        if d[m[1]]>d[m[0]]:
            answer+=m[1]
        else:
            answer+=m[0]

    return answer