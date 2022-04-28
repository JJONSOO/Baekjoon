#include <string>
#include <vector>

using namespace std;
bool visited[20][20][20];
vector<int> Node[20];
vector<int>state;
int ans;
void Init(vector<vector<int>> edges){
    for(auto n:edges){
        Node[n[0]].push_back(n[1]);
        Node[n[1]].push_back(n[0]);
    }
}
void DFS(int sheep,int wolf,int start){
    if(start==0){
        ans=max(ans,sheep);
    }
    for(auto next:Node[start]){
        if(state[next]==0){
            if(visited[next][sheep+1][wolf]==false){
                visited[next][sheep+1][wolf]=true;
                state[next]=-1;
                DFS(sheep+1,wolf,next);
                state[next]=0;
                visited[next][sheep+1][wolf]=false;
            }
        }
        else if(state[next]==1){
            if(visited[next][sheep][wolf+1]==false&&sheep>wolf+1){
                visited[next][sheep][wolf+1]=true;
                state[next]=-1;
                DFS(sheep,wolf+1,next);
                state[next]=1;
                visited[next][sheep][wolf+1]=false;
            }
        }
        else{
            if(visited[next][sheep][wolf]==false){
                visited[next][sheep][wolf]=true;
                DFS(sheep,wolf,next);
                visited[next][sheep][wolf]=false;
            }
        }   
        }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    state=info;
    state[0]=-1;
    visited[0][1][0]=true;
    Init(edges);
    DFS(1,0,0);
    return ans;
}