#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int V;

#define INF 5000000
int ans = INF;

vector<pair<int,int>> p[201];
int a_dist[201];
int b_dist[201];
int s_dist[201];
void Dijk(int start,int state){
    int dist[V+1];    
    fill(dist,dist+V+1,INF);    
    priority_queue<pair<int,int> > qu;     
    
    qu.push({0,start});    
    dist[start]=0;    
    
    while(!qu.empty()){
        int cost=-qu.top().first;    
        int here=qu.top().second;     
        
        qu.pop();
            
        for(int i=0; i<p[here].size(); i++){
            int next=p[here][i].first;
            int nextcost=p[here][i].second;
            
            if(dist[next] > dist[here] + nextcost){    

                dist[next]=dist[here]+nextcost;
                qu.push({-dist[next],next});
            }
        }
        
    }

    if(state==0){
        for(int i=1;i<V;i++){
            s_dist[i]=dist[i];
        }
    }
    if(state==1){
        for(int i=1;i<V;i++){
            a_dist[i]=dist[i];
        }

    }
    if(state==2){
        for(int i=1;i<V;i++){
            b_dist[i]=dist[i];
        }
    }
    
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    V=n+1;

    int answer = 0;
    for(int i=0;i<fares.size();i++){
            p[fares[i][0]].push_back({fares[i][1],fares[i][2]});
            p[fares[i][1]].push_back({fares[i][0],fares[i][2]});
    }

    for(int i=1;i<V;i++){
        a_dist[i]=INF;
        b_dist[i]=INF;
        s_dist[i]=INF;
    }
    Dijk(s,0);
    Dijk(a,1);
    Dijk(b,2);

    int cost=987654321;
    for(int i=1;i<V;i++){
            cost=min(cost,a_dist[i]+b_dist[i]+s_dist[i]);
        }
    
    return cost;
}

