#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N,M;
vector<int> a[101];
int rs[101][101];
queue<int> q;
void bfs(int start){
    int v[101]={0,};
    q.push(start);
    v[start]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<a[x].size();i++){
            int idx = a[x][i];
            if(v[idx]==0){
                v[idx]=1;
                q.push(idx);
                rs[idx][start]=rs[x][start]+1;
                rs[start][idx]=rs[start][x]+1;
            }

        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            rs[i][j]=0;
        }
    }
    for(int i=1;i<=N;i++)
        bfs(i);
    int sum=0;
    int result=0;
    int min = 987654321;
    for(int i=1;i<=N;i++){
        sum=0;
        for(int j=1;j<=N;j++){
            sum+=rs[i][j];
        }
        if(min>sum){
            min=sum;
            result=i;
        }
    }
    cout<<result<<"\n";
}
