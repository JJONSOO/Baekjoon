#include<iostream>
using namespace std;
int N,S;
int arr[1000001];
int ans=987654321;
void init(){
    cin>>N>>S;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        if(i>0)arr[i]+=arr[i-1];
    }
}
void solve(){
    int left=0;
    int right=0;
    while(right<=N){
        if(arr[right]-arr[left]>=S){
            if(right-left<ans)
                ans=right-left;
            left++;
        }
        else {
            right++;
        }
    }
    if(ans==987654321)
        cout<<"0"<<endl;
    else
        cout<<ans<<endl;
}
int main(){
    init();
    solve();
}