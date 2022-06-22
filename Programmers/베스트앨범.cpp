#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
struct album{
    string genre;
    vector<pair<int,int>> play;
    int total;
    album(string g, vector<pair<int,int>> p){
        genre=g;
        play=p;
        total=0;
    }
};
bool al_sort(album a , album b){
    return a.total > b.total;
}
bool album_sort(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second>b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<album> al;
    for(int i=0;i<genres.size();i++){
        bool ck=true;
        for(int j=0;j<al.size();j++){
            if(al.at(j).genre==genres.at(i)){
                al.at(j).play.push_back(pair<int,int>(i,plays.at(i)));
                al.at(j).total+=plays.at(i);
                ck=false;
                break;
            }
        }
        if(ck){
            vector<pair<int,int>> p;
            p.push_back(pair<int,int>(i,plays.at(i)));
            al.push_back(album(genres.at(i),p));
            al.at(al.size()-1).total+=plays.at(i);
        }
    }

    sort(al.begin(),al.end(),al_sort);
    for(int i=0;i<al.size();i++){
        sort(al.at(i).play.begin(),al.at(i).play.end(),album_sort);

        if(al.at(i).play.size()==1){
            answer.push_back(al.at(i).play.at(0).first);
        }
        else{
            answer.push_back(al.at(i).play.at(0).first);
            answer.push_back(al.at(i).play.at(1).first);
        }
    }
    return answer;
}