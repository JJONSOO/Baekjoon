#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<pair<int,int>> times;
int MaxCnt;
void Init(vector<string> lines){
    for(int i=0;i<lines.size();i++){
        //Time구하기
        int time_idx=0;
        for(int j=lines[i].size()-1;j>0;j--){
            if(lines[i].at(j)==' '){
                time_idx=j;
                break;
            }
        }
        string tmp;
        for(int j=time_idx+1;j<lines[i].size()-1;j++){
            tmp+=lines[i].at(j);
        }
        float time=stof(tmp);
        // cout<<time<<endl;
        // // //9월15일 시간 구하기
        int time_idx2;
        for(int j=0;j<lines[i].size();j++){
            if(lines[i].at(j)==' '){
                time_idx2=j;
                break;
            }
        
        }
        string tmp2;
        for(int j=time_idx2+1;j<time_idx;j++){
            if(lines[i].at(j)!=':'&&lines[i].at(j)!='.')
                tmp2+=lines[i].at(j);
        }
        
        int start_time=stoi(tmp2);
        int ch=int(time*1000);

        int first_num=start_time;
        int x=0;
        for(int i=0;i<ch;i++){
            first_num--;
            if(first_num%10000000>=6000000){
                first_num-=4040000;
            }
            else if (first_num%100000>=60000){
                first_num-=40000;

            }
            
        }
        times.push_back(make_pair(first_num,start_time));

    }
}
void Cal(){

    for(int i=0;i<times.size();i++){
        int cnt=0;
        int start_time=(times[i].second)-1;
        int end_time=start_time+1000;
        if((int(end_time)%100000)>=60000){
            //분
            end_time+=100000.0;
            end_time-=60000.0;
            //시
            if(int(end_time)%10000000>=6000000){
                end_time+=10000000.0;
                end_time-=6000000.0;
            }
        }
        for(int j=0;j<times.size();j++){
            if(times[j].first<=start_time&&times[j].second>start_time){
                cnt++;
            }
            else if(times[j].first>=start_time&&times[j].first<end_time){
                cnt++;
            }
        }
        if(cnt>MaxCnt)
            MaxCnt=cnt;
    }
}
int solution(vector<string> lines) {
    int answer = 0;
    Init(lines);
    Cal();
    return MaxCnt;
}


