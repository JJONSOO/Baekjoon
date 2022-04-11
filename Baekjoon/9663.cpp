#include<iostream>
using namespace std;
int n;
int ans;
int col[15];
void Init(){
    cin>>n;
}
bool check(int level){
    for(int i=0;i<level;i++){
        if(col[i]==col[level]||abs(col[level]-col[i])==level-i)
            return false;
    }
    return true;
}
void Solve(int x){
    if(x==n)
        ans++;
    else{
        for(int i=0;i<n;i++){
            col[x]=i;
            if(check(x))
                Solve(x+1);
        }
    }
}
int main(){
    Init();
    Solve(0);
    cout<<ans<<endl;

}