#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int> > tree[10001];
int n;
int end_point;
int ans,total;
bool visited[100001];
void dfs(int cur,int cur_total){
    if(visited[cur])return;
    visited[cur]=true;
    if(cur_total>total){
        end_point=cur;
        total=cur_total;
    }
    for(int i=0;i<tree[cur].size();i++){
        dfs(tree[cur][i].first,cur_total+tree[cur][i].second);
    }
}
void Input(){
    for(int i=1;i<n;i++){
        int start,end,cost;
        tree[start].push_back(make_pair(end,cost));
        tree[end].push_back(make_pair(start,cost));
    }
}
void Init(){
    for(int i=0;i<100001;i++)
        visited[i]=false;
    }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    dfs(1,0);
    Init();
    dfs(end_point,0);
    cout<<total<<endl;
}