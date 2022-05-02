#include <string>
#include <vector>
#include <queue>
using namespace std;
int ans=987654321;
bool visited[25][25];
int dist[26][26][4];
void DFS(int cost ,int x, int y, vector<vector<int>> board, string direction){

    if(cost>=ans)
        return;
    if(x==board.size()-1&&y==board.size()-1){
        if(cost<ans){
            ans=cost;
        }
        return ;
    }
        if(direction=="up"){

        if(y-1>=0&&!visited[x][y-1]&&board[x][y-1]==0){
        if(dist[x][y][2]!=987654321&&dist[x][y][2]<cost)
            return;
        dist[x][y][2]=min(dist[x][y][2],cost);
            visited[x][y-1]=true;
            DFS(cost+600,x,y-1,board,"down");
            visited[x][y-1]=false;


        }

        if(x-1>=0&&!visited[x-1][y]&&board[x-1][y]==0){
        if(dist[x][y][3]!=987654321&&dist[x][y][3]<cost)
            return;
        dist[x][y][3]=min(dist[x][y][3],cost);
            visited[x-1][y]=true;
            DFS(cost+600,x-1,y,board,"left");
            visited[x-1][y]=false;


        }

        if(y+1<board.size()&&!visited[x][y+1]&&board[x][y+1]==0){
        if(dist[x][y][0]!=987654321&&dist[x][y][0]<cost)
            return;
        dist[x][y][0]=min(dist[x][y][0],cost);
            visited[x][y+1]=true;
            DFS(cost+100,x,y+1,board,"up");
            visited[x][y+1]=false;

        }
        if(x+1<board.size()&&!visited[x+1][y]&&board[x+1][y]==0){
        if(dist[x][y][1]!=987654321&&dist[x][y][1]<cost)
            return;
        dist[x][y][0]=min(dist[x][y][0],cost);
            visited[x+1][y]=true;
            DFS(cost+600,x+1,y,board,"right");
            visited[x+1][y]=false;

        }
    }
    if(direction=="down"){


        if(y-1>=0&&!visited[x][y-1]&&board[x][y-1]==0){
        if(dist[x][y][2]!=987654321&&dist[x][y][2]<cost)
            return;
        dist[x][y][2]=min(dist[x][y][2],cost);
            visited[x][y-1]=true;
            DFS(cost+100,x,y-1,board,"down");
            visited[x][y-1]=false;


        }

        if(x-1>=0&&!visited[x-1][y]&&board[x-1][y]==0){
        if(dist[x][y][3]!=987654321&&dist[x][y][3]<cost)
            return;
        dist[x][y][3]=min(dist[x][y][3],cost);
            visited[x-1][y]=true;
            DFS(cost+600,x-1,y,board,"left");
            visited[x-1][y]=false;


        }
                if(y+1<board.size()&&!visited[x][y+1]&&board[x][y+1]==0){
        if(dist[x][y][0]!=987654321&&dist[x][y][0]<cost)
            return;
        dist[x][y][0]=min(dist[x][y][0],cost);
            visited[x][y+1]=true;
            DFS(cost+600,x,y+1,board,"up");
            visited[x][y+1]=false;

        }
        if(x+1<board.size()&&!visited[x+1][y]&&board[x+1][y]==0){
        if(dist[x][y][1]!=987654321&&dist[x][y][1]<cost)
            return;
        dist[x][y][0]=min(dist[x][y][0],cost);
            visited[x+1][y]=true;
            DFS(cost+600,x+1,y,board,"right");
            visited[x+1][y]=false;

        }
    }
    if(direction=="right"){

        
        if(y-1>=0&&!visited[x][y-1]&&board[x][y-1]==0){
        if(dist[x][y][2]!=987654321&&dist[x][y][2]<cost)
            return;
        dist[x][y][2]=min(dist[x][y][2],cost);
            visited[x][y-1]=true;
            DFS(cost+600,x,y-1,board,"down");
            visited[x][y-1]=false;


        }

        if(x-1>=0&&!visited[x-1][y]&&board[x-1][y]==0){
        if(dist[x][y][3]!=987654321&&dist[x][y][3]<cost)
            return;
        dist[x][y][3]=min(dist[x][y][3],cost);
            visited[x-1][y]=true;
            DFS(cost+600,x-1,y,board,"left");
            visited[x-1][y]=false;


        }
        if(y+1<board.size()&&!visited[x][y+1]&&board[x][y+1]==0){
        if(dist[x][y][0]!=987654321&&dist[x][y][0]<cost)
            return;
        dist[x][y][0]=min(dist[x][y][0],cost);
            visited[x][y+1]=true;
            DFS(cost+600,x,y+1,board,"up");
            visited[x][y+1]=false;

        }
        if(x+1<board.size()&&!visited[x+1][y]&&board[x+1][y]==0){
        if(dist[x][y][1]!=987654321&&dist[x][y][1]<cost)
            return;
        dist[x][y][0]=min(dist[x][y][0],cost);
            visited[x+1][y]=true;
            DFS(cost+100,x+1,y,board,"right");
            visited[x+1][y]=false;

        }
    }
    if(direction=="left"){

    
        if(y-1>=0&&!visited[x][y-1]&&board[x][y-1]==0){
        if(dist[x][y][2]!=987654321&&dist[x][y][2]<cost)
            return;
        dist[x][y][2]=min(dist[x][y][2],cost);
            visited[x][y-1]=true;
            DFS(cost+600,x,y-1,board,"down");
            visited[x][y-1]=false;


        }

        if(x-1>=0&&!visited[x-1][y]&&board[x-1][y]==0){
        if(dist[x][y][3]!=987654321&&dist[x][y][3]<cost)
            return;
        dist[x][y][3]=min(dist[x][y][3],cost);
            visited[x-1][y]=true;
            DFS(cost+100,x-1,y,board,"left");
            visited[x-1][y]=false;


        }
        if(y+1<board.size()&&!visited[x][y+1]&&board[x][y+1]==0){
        if(dist[x][y][0]!=987654321&&dist[x][y][0]<cost)
            return;
        dist[x][y][0]=min(dist[x][y][0],cost);
            visited[x][y+1]=true;
            DFS(cost+600,x,y+1,board,"up");
            visited[x][y+1]=false;

        }
        if(x+1<board.size()&&!visited[x+1][y]&&board[x+1][y]==0){
        if(dist[x][y][1]!=987654321&&dist[x][y][1]<cost)
            return;
        dist[x][y][0]=min(dist[x][y][0],cost);
            visited[x+1][y]=true;
            DFS(cost+600,x+1,y,board,"right");
            visited[x+1][y]=false;

        }          }

}

int solution(vector<vector<int>> board) {
    visited[0][0]=true;
    if(board[0][1]==0){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<4;k++)
                    dist[i][j][k]=987654321;
            }
        }
        visited[0][1]=true;
        DFS(100,0,1,board,"up");
        visited[0][1]=false;
    }
    if(board[1][0]==0){
        visited[1][0]=true;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                    for(int k=0;k<4;k++)
                        dist[i][j][k]=987654321;
            }
        }
        DFS(100,1,0,board,"right");
    }
    // visited[1][0]=true;

    return ans;
}