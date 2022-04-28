    #include <string>
    #include <vector>
    #include<iostream>

    using namespace std;
    int basic_time;
    int basic_cost;
    int unit_time;
    int unit_cost;
    vector<pair<int,int>>graph[9999];//in시간,총시간
    vector<int> solution(vector<int> fees, vector<string> records) {
        vector<int> answer;
        basic_time=fees[0];
        basic_cost=fees[1];
        unit_time=fees[2];
        unit_cost=fees[3];
        for(auto a:records){
            int time=stoi(a.substr(0,2))*60+stoi(a.substr(3,2));
            int number=stoi(a.substr(6,4));
            string state=a.substr(11);
            if(state=="IN"){
                if(graph[number].size()==0){
                    graph[number].push_back(make_pair(time,0));
                }
                else{
                    graph[number][0].first=time;
                }
            }
            if(state=="OUT"){
                graph[number][0].second+=(time-graph[number][0].first);
                graph[number][0].first=-1;
            }
            
        }
        for(int i=0;i<9999;i++){
            if(graph[i].size()>0&&graph[i][0].first>=0){
                graph[i][0].second+=((23*60+59)-graph[i][0].first);
            }
        }
        for(int i=0;i<9999;i++){
            if(graph[i].size()>0&&graph[i][0].second>0){
                int cost=basic_cost;
                int time=graph[i][0].second-basic_time;
                if(time<0)
                    answer.push_back(cost);
                else{
                    if(time%unit_time>0){
                        cost+=((time/unit_time)+1)*unit_cost;
                    }
                    else{
                        cost+=((time/unit_time))*unit_cost;
                    }
                    answer.push_back(cost);
                }
            }
        }
        return answer;
    }