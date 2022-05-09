#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int>a[200];
bool visited[200];
int cnt=0;
void DFS(int start){
    if(!visited[start]){
        cnt++;
        visited[start]=true;
        for(int i=0;i<a[start].size();i++){
            DFS(a[start].at(i));
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers.at(i).size();j++){
            if(i!=j&&computers.at(i).at(i)==1&&computers.at(j).at(i)==1)
                a[j].push_back(i);
        }
    }
    for(int i=0;i<n;i++){
        DFS(i);
        if(cnt){
            answer++;
            cnt=0;
        }
    }
    return answer;
}