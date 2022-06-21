#include<iostream>
#include<queue>

using namespace std;
int V,E,A,B,C;
int Node[10000];
int parent[10000];
int ans;

struct edge {
    int start_node;
    int end_node;
    int weight;
    edge(int s_n,int e_n,int w){
        start_node=s_n;
        end_node=e_n;
        weight=w;
    }
    bool operator<(const edge e) const{
        return this->weight > e.weight;
    }
};
priority_queue<edge> pq;
int Find(int v){
    if(parent[v]==v)
        return v;
    else return parent[v]=Find(parent[v]);
}
void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a!=b) parent[a]=b;
}
void init(){
    cin>>V>>E;
    for(int i=1;i<=V;i++){
        parent[i]=i;
    }
    for(int i=0;i<E;i++){
        cin>>A>>B>>C;
        pq.push(edge(A,B,C));
    }
}
void solve(){
    while(!pq.empty()){
        edge e = pq.top();
        int fa=Find(e.start_node);
        int fb=Find(e.end_node);
        if(fa!=fb){
            ans+=e.weight;
            Union(e.start_node,e.end_node);
        }
        pq.pop();
    }
    cout<<ans;

}
int main(){
    init();
    solve();
}