#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N,K,X,Y,Z,D,T,W;
int ans;

vector<int> building[100000];
int building_cost[1001];
int final_cost[1001];
int Entry[1001];
void Init(){
    cin>>T;
    for(int test_num=0;test_num<T;test_num++){
        memset(building_cost,0,sizeof(building_cost));
        memset(final_cost,0,sizeof(final_cost));
        memset(Entry,0,sizeof(Entry));
        for(int i=0;i<1000;i++)building[i].clear();
        cin>>N>>K;
        for(int node_cost=1;node_cost<=N;node_cost++){
            cin>>D;
            building_cost[node_cost]=D;
        }
        for(int node_num=0;node_num<K;node_num++){
            cin>>X>>Y;
            building[X].push_back(Y);
            Entry[Y]++;
        }
        cin>>W;
        queue<int>q;
        for(int i=1;i<=N;i++){
            if(Entry[i]==0){
                q.push(i);
                final_cost[i]=building_cost[i];
                // cout<<"i: "<<i<<endl;
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            for(int i=0;i<building[f].size();i++){
                final_cost[building[f].at(i)] = max(final_cost[building[f].at(i)],final_cost[f]+building_cost[building[f].at(i)]);
                Entry[building[f].at(i)]--;
                if(Entry[building[f].at(i)]==0)
                    q.push(building[f].at(i));
            }
        }
        cout<<final_cost[W]<<endl;        
    }
}

int main(){
    Init();
}