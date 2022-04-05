#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int dist[20001];
int V,E,K;
vector<pair<int,int>> v[20001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>V>>E>>K;
    for(int i=1;i<=V;i++){
        dist[i]=987654321;
    }
    for(int i=0;i<E;i++){
        int start,end,cost;
        cin>>start>>end>>cost;
        v[start].push_back(make_pair(end,cost));
    }
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,K));
    dist[K]=0;

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
    for(int i=1;i<=V;i++){
        if(dist[i]==987654321)cout<<"INF"<<"\n";
        else cout<<dist[i]<<"\n";
    }
}