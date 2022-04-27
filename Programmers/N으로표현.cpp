#include<string>
#include<vector>

using namespace std;

int arr[8];
int MaxCnt=9;
void Init(int N){
    int tmp=0;
    for(int i=0;i<8;i++){
        arr[i]=tmp*10+N;
        tmp=arr[i];
    }
}
void DFS(int cnt,int number,int cur_num,int N){
    if(cnt>=MaxCnt)return;
    if(cur_num==number){
        if(MaxCnt>cnt)
            MaxCnt=cnt;
        return;
    }
    for(int i=0;i<8;i++){
        int tmp=(i+1);
        DFS(cnt+tmp,number,cur_num+arr[i],N);
        DFS(cnt+tmp,number,cur_num-arr[i],N);
        DFS(cnt+tmp,number,cur_num*arr[i],N);
        DFS(cnt+tmp,number,cur_num/arr[i],N);
    }

}
int solution(int N,int number){
    int answer=0;
    Init(N);
    DFS(0,number,0,N);
    if(MaxCnt>8)return -1;
    return MaxCnt;
}