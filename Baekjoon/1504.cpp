#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int main() {
    int answer = 0;
    int N,E;
    cin>>N>>E;
    priority_queue<pair<int,int> > pq;
    vector<pair<int,int> > v[1001];
    for(int i=0;i<E;i++){
        int start,end,cost;
        cin>>start>>end>>cost;
        v[start].push_back(make_pair(cost,end));
        v[end].push_back(make_pair(cost,start));

    }
    int a,b;
    cin>>a>>b;
    int dist[20000];
    for(int i=1;i<=20000;i++){
        dist[i]=987654321;
    }
    dist[1]=0;
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;

        pq.pop();
        for(int i=0;i<v[cur].size();i++){
            int nextcur=v[cur][i].second;
            int next_cost = v[cur][i].first;

            if(cost+next_cost<dist[nextcur]){
                dist[nextcur]=cost+next_cost;
                pq.push(make_pair(-dist[nextcur],nextcur));
            }
        }
    }
        priority_queue<pair<int,int> > pq2;

int dist2[20000];
    for(int i=1;i<=20000;i++){
        dist2[i]=987654321;
    }
    dist2[a]=0;
    pq2.push(make_pair(0,a));
    while(!pq2.empty()){
        int cost = -pq2.top().first;
        int cur = pq2.top().second;


        pq2.pop();
        for(int i=0;i<v[cur].size();i++){
            int nextcur=v[cur][i].second;
            int next_cost = v[cur][i].first;

            if(cost+next_cost<dist2[nextcur]){
                dist2[nextcur]=cost+next_cost;
                pq2.push(make_pair(-dist2[nextcur],nextcur));
            }
        }
    }

    int dist3[20000];
    for(int i=1;i<=20000;i++){
        dist3[i]=987654321;
    }
        priority_queue<pair<int,int> > pq3;

    dist3[b]=0;
    pq3.push(make_pair(0,b));
    while(!pq3.empty()){
        int cost = -pq3.top().first;
        int cur = pq3.top().second;

        pq3.pop();
        for(int i=0;i<v[cur].size();i++){
            int nextcur=v[cur][i].second;
            int next_cost = v[cur][i].first;

            if(cost+next_cost<dist3[nextcur]){
                dist3[nextcur]=cost+next_cost;
                pq3.push(make_pair(-dist3[nextcur],nextcur));
            }
        }
    }
    int x = dist[a]+dist2[b]+dist3[N];
    int y = dist[b]+dist3[a]+dist2[N];

    if(x>y){
        if(y>0&&y<987654321)cout<<y<<endl;
        else if(x>0&&x<987654321)cout<<x<<endl;
        else cout<<"-1"<<endl;
    }
    else{
        if(x>0&&x<987654321)cout<<x<<endl;
        else if(y>0&&y<987654321)cout<<y<<endl;
        else cout<<"-1"<<endl;
    }

    return 0;
}