#include<iostream>
using namespace std;
int arr[16][16];
int n;
int ans;
void Init(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[j][i];
        }
    }

}
void Solve(int state,int x,int y){
    //ㅏ가로
    if((x==n-1)&&(y==n-1)){
        ans++;
    }
    if(state==0){
        if(x<n-1&&arr[x+1][y]!=1){
            Solve(state,x+1,y);
        }
        if(x<n-1&&y<n-1&&arr[x+1][y]!=1&&arr[x+1][y+1]!=1&&arr[x][y+1]!=1){
            Solve(2,x+1,y+1);
        }
    }
    //세로
    if(state==1){
        
        if(y<n-1&&arr[x][y+1]!=1){
            Solve(state,x,y+1);
        }
        if(x<n-1&&y<n-1&&arr[x+1][y]!=1&&arr[x+1][y+1]!=1&&arr[x][y+1]!=1){
            Solve(2,x+1,y+1);
        }
    }
    //대각선
    if(state==2){
        if(x<n-1&&arr[x+1][y]!=1){
            Solve(0,x+1,y);
        }
        if(y<n-1&&arr[x][y+1]!=1){
            Solve(1,x,y+1);
        }
        if(x<n-1&&y<n-1&&arr[x+1][y]!=1&&arr[x+1][y+1]!=1&&arr[x][y+1]!=1){
            Solve(2,x+1,y+1);
        }
    }

}
int main(){
    Init();
    Solve(0,1,0);
    cout<<ans<<"\n";
}