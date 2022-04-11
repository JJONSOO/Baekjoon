#include<iostream>
#include<string>
using namespace std;
int R,C;
int arr[20][20];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans;
bool visit[26]={false,};
void Init(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        string str;
        cin>>str;
        for(int j=0;j<C;j++){
            arr[j][i]=(str.at(j)-65);
        }
    }

}
void Solve(int x,int y,int cnt,bool visited[26]){
    if(cnt+1>ans){
        ans=cnt+1;
    }
    for(int i=0;i<4;i++){
        if(x+dx[i]<C&&x+dx[i]>-1&&y+dy[i]<R&&y+dy[i]>-1){
            if(!visited[arr[x][y]]){
                        visited[arr[x][y]]=true;
                Solve(x+dx[i],y+dy[i],cnt+1 ,visited);
                        visited[arr[x][y]]=false;

        }
    }
    }
}
int main(){
    Init();
    Solve(0,0,1,visit);
    cout<<ans-2<<endl;
}