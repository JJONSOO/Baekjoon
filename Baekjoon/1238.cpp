#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N,M,X,ans;
int dist[10001];
int Res[10001];
vector<pair<int,int> > v[1001];
void DijkStra(int start){
    for(int i=1;i<=N;i++)
        dist[i]=987654321;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));
    dist[start]=0;

    while(!pq.empty()){
        int cur=pq.top().second;
        int cur_cost=-pq.top().first;
        pq.pop();

        for(int i=0;i<v[cur].size();i++){
            int next_cur=v[cur][i].first;
            int next_cost=v[cur][i].second;
            if(dist[next_cur]>cur_cost+next_cost){
                dist[next_cur]=next_cost+cur_cost;
                pq.push(make_pair(-dist[next_cur],next_cur));
                
            }
        }
    }
}
void Solution()
{
    for(int i = 1; i <= N; i++)
    { 
        for (int j = 1; j <= N; j++) dist[j] = 987654321;
        DijkStra(i);
        Res[i] = dist[X];        
    }
    for (int j = 1; j <= N; j++) dist[j] = 987654321;
    DijkStra(X);
    for (int i = 1; i <= N; i++) Res[i] = Res[i] + dist[i];
    sort(Res + 1, Res + N + 1);
    ans = Res[N];
    cout<<ans<<endl;
}
void Init(){
    cin>>N>>M>>X;
    for(int i=0;i<M;i++){
        int start,end,cost;
        cin>>start>>end>>cost;
        v[start].push_back(make_pair(end,cost));
    }
}
int main(){
    Init();
    Solution();
}