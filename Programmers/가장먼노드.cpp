#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int> > edge) {
    int answer = 0;
    priority_queue<pair<int,int> > pq;
    vector< vector<int> > v(n+1);
    for(int i=0;i<edge.size();i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);

    }
    int dist[20000];
    for(int i=1;i<=20000;i++){
        dist[i]=987654321;
    }
    dist[1]=0;
    pq.push(make_pair(0,1));
    int max=0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        if(cost>max)
            max=cost;

        pq.pop();
        for(int i=0;i<v[cur].size();i++){
            int nextcur=v[cur][i];
            int next_cost = 1;

            if(cost+next_cost<dist[nextcur]){
                dist[nextcur]=cost+next_cost;
                pq.push(make_pair(-dist[nextcur],nextcur));
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i]==max)
            answer++;
    }
    return answer;
}