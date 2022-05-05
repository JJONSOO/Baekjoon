from collections import defaultdict
from email.policy import default
import re

def solution(word, pages):
    answer = 0
    links=defaultdict(list)
    word=' '+word.lower()+' '


    for page in pages:
        page_start=page.find('<meta property="og:url" content')
        page_end=page.find('/>',page_start+33)
        page_id=page[page_start+33:page_end-1]
        # print(page_id)
        links[page_id]
        
        # body_start=page.find('<body>')
        # body_end=page.find('<\body>')
        # body=page[body_start+6:body_end-1]
        
        #외부링크
        p_tag_list=[]
        p = re.compile('(?<=\<a href=")(.*?)(?=\">)') 
        p_tag_list = p.findall(page)
        (links[page_id].append(p_tag_list))
        
        #기본 점수 찾기
        page=page.lower()
        for i in p_tag_list:
            i=i.lower()
            page.replace(i,'')
        tmp = re.sub('[-=+,#/\?:^.@*\※~ㆍ!』‘|\(\)\%&[<>\]`$…》\”\“\{’}·_0123456789""]', ' ', page)
        page = ' '.join(tmp.split())
        print(tmp)
        cnt=0
        idx=0

        
        while page.find(word,idx)>=0:
            idx=page.find(word,idx)+1
            cnt+=1
        links[page_id].append(cnt)
    print(links)

    sc=[0 for i in range(len(links))]
    # print(sc)
    for index ,(key,value) in enumerate(links.items()):
        if(len(value[0])!=0):
            score = value[1]/len(value[0])
            sc[index]+=value[1]
            for v in value[0]:
                if links.get(v):
                    sc[list(links).index(v)]+=(score)
        else :
            sc[index]+=value[1]

    return sc.index(max(sc))