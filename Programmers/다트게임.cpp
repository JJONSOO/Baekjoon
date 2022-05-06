#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> num;
    string tmp;
    for(int i=0;i<dartResult.size();i++){
        if(dartResult.at(i)-'0'>=0&&dartResult.at(i)-'0'<=9){
            // string str= dartResult.at(i)-'0';
            tmp+=to_string((dartResult.at(i)-'0'));
        }
        else if(dartResult.at(i)=='S'){
            num.push_back(stoi(tmp));
            tmp="";
        }
        else if(dartResult.at(i)=='D'){
            num.push_back(stoi(tmp)*stoi(tmp));
            tmp="";
        }
        else if(dartResult.at(i)=='T'){
            num.push_back(stoi(tmp)*stoi(tmp)*stoi(tmp));
            tmp="";
        }
        else if(dartResult.at(i)=='*'){
            if(num.size()==3){
                num.at(2)=num.at(2)*2;
                num.at(1)=num.at(1)*2;

            }
            if(num.size()==2){
                num.at(1)=num.at(1)*2;
                num.at(0)=num.at(0)*2;

            }
            if(num.size()==1){
                num.at(0)=num.at(0)*2;

            }
        }
        else if(dartResult.at(i)=='#'){
            num.at(num.size()-1)=-num.at(num.size()-1);
        }
    }
    for(int i=0;i<num.size();i++){
        answer+=num.at(i);
        cout<<num.at(i)<<endl;
    }
    return answer;
}