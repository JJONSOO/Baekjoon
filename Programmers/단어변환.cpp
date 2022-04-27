#include <string>
#include <vector>
#include <iostream>
using namespace std;
int ans=987654321;
void dfs(string begin,string target,vector<string> words,bool visited[100],int cnt){
    if(begin==target){
        // cout<<begin<<" "<<target<<endl;
        if(cnt-1<ans)ans=cnt-1;
        return;
    }
    else{
        for(int i=0;i<words.size();i++){
            int diff=0;
            for(int j=0;j<begin.length();j++){
                if(begin.at(j)!=words[i].at(j))diff++;
                if(diff>2)break;
            }
            if(diff==1&&!visited[i]){
                visited[i]=true;
                // cout<<words[i]<<endl;
                dfs(words[i],target,words,visited,cnt+1);
                visited[i]=false;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool ck=true;
    for(int i=0;i<words.size();i++){
        if(words[i]==target)ck=false;
    }
    if(ck)return 0;
    bool visited[100];
    for(int i=0;i<101;i++)
        visited[i]=false;
    dfs(begin,target,words,visited,0);
    return ans;
}