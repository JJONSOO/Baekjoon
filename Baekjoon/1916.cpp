#include<iostream>
#include<queue>
#include<vector>
int dist[1001];
using namespace std;
vector<pair<int,int> > v[1001];

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int start,end,cost;
        cin>>start>>end>>cost;
        v[start].push_back({end,cost});
    }
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=N;i++)
        dist[i]=1000000;
    int start;
    int end;
    cin>>start>>end;
    dist[start]=0;
    pq.push(make_pair(start,0));
    while(!pq.empty()){
        int cur=pq.top().first;
        int cost=-pq.top().second;
        pq.pop();
        if(dist[cur]<cost)
            continue;
        for(int i=0;i<v[cur].size();i++){
            int nextcur=v[cur][i].first;
            int nextcost=v[cur][i].second;
            if(dist[nextcur]>nextcost+dist[cur]){
                dist[nextcur]=dist[cur]+nextcost;
                pq.push(make_pair(nextcur,-nextcost));
            }

        }
    }
    cout<<dist[end];

}