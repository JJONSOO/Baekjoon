#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;


int solution(std::vector<int> a) {
    int answer = -1;
    unordered_map<int,int> um;
    for(int i=0;i<a.size();i++){
        um[a[i]]++;
    }
    for(auto it : um){
        int tmp=0;
        if(it.second*2<=answer)continue;

        for(int i=0;i<a.size()-1;i++){
            if(a[i]==a[i+1])continue;
            if(a[i]!=it.first&&a[i+1]!=it.first)continue;
            tmp+=2;
            i++;
        }
        answer=max(answer,tmp);
    }
    return answer;
}