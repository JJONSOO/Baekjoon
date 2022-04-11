#include <iostream>
#include <algorithm>
using namespace std;
    int n;

int arr[501][501];
int dp[501][501] = {0};
void Init(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }
}
void Solve(){
    dp[1][1] = arr[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j];
        }
    }
    int max = 0;
    for(int i = 1; i <= n; i++){
        if(max < dp[n][i])
            max = dp[n][i];
    }
    
    cout << max << '\n';
}
int main(int argc, const char * argv[]) {

    Init();
    Solve();
}
