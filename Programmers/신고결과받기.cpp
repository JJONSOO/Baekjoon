#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> ban_list[1000];
int arr[1000];
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(auto a:report){
        int idx,idx2;
        for(int i=0;i<a.size();i++){
            if(a.at(i)==' '){
                idx=i;
            }
        }
        string first=a.substr(0,idx);
        string second=a.substr(idx+1,a.length()-idx);
        for(int i=0;i<id_list.size();i++){
                if(first==id_list[i])idx=i;
                if(second==id_list[i]){
                    idx2=i;
                }       
        }
        bool tmp=false;
        for(int i=0;i<ban_list[idx].size();i++){
            if(ban_list[idx].at(i)==idx2)
                tmp=true;
        }
        if(!tmp){
            arr[idx2]+=1;
            ban_list[idx].push_back(idx2);
        }
    }
    for(int i=0;i<id_list.size();i++){
        int num=0;
        for(int j=0;j<ban_list[i].size();j++){
            if(arr[ban_list[i].at(j)]>=k){
                num++;
            }
        }
        answer.push_back(num);
    }
    return answer;
}