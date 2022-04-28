#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int>ans;
int max_cnt=0;
void DFS(int round,vector<int>info,int apachi,int ryan,int cnt,vector<int>ryan_info){
    if(round==-1&&cnt==0){
        if(ryan>apachi&&ryan-apachi>max_cnt){
            max_cnt=ryan-apachi;
            ans=ryan_info;
        }
        else if(ryan>apachi&&ryan-apachi==max_cnt){
            for(int i=ryan_info.size()-1;i>-1;i--){
                // cout<<"ans: "<<i<<" "<<"ans size: "<<ans.size()<<" i번째 ans: "<<ans.at(i)<<endl;
                if(ryan_info.at(i)>ans.at(i)){
                    ans=ryan_info;
                    break;
                }
                else if(ans.at(i)>ryan_info.at(i)){
                    break;
                }
            }
        }
    }
    else if(round>=0){
        int arrow=cnt;
        while(arrow>=0){
            ryan_info.at(10-round)=arrow;
            if(info.at(10-round)==0&&ryan_info.at(10-round)==0)
                DFS(round-1,info,apachi,ryan,cnt-arrow,ryan_info);
            else if(info.at(10-round)>=arrow){
                DFS(round-1,info,apachi+round,ryan,cnt-arrow,ryan_info);
            }
            else if(info.at(10-round)<arrow){
                DFS(round-1,info,apachi,ryan+round,cnt-arrow,ryan_info);
            }
            arrow--;
        }
    }
}
vector<int> solution(int n, vector<int> info) {
    ans.push_back(-1);
    vector<int> tmp;
    for(auto a:info){
        tmp.push_back(0);
    }
    DFS(10,info,0,0,n,tmp);
    return ans;
}