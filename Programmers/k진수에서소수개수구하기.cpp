#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    string str="";
    while(true){
        if(n/k==0){
            str=to_string(n)+str;
            break;
        }

        str=to_string(n%k)+str;
        n=n/k;
    }
    string tmp="";
    vector<long>a;
    for(int i=0;i<str.length();i++){
        if(str.at(i)!='0'){
            tmp+=str.at(i);
        }
        else{
            if(tmp!="")a.push_back(stol(tmp));
            tmp="";
        }

    }
    if(tmp!=""){
        a.push_back(stol(tmp));
    }


    for(auto x:a){
        bool ck=true;
        if(x<2){
            ck=false;
        }
        else{
            int y=(int)sqrt(x);
            for(int i=2;i<=y;i++){
                if(x%i==0){
                    ck=false;
                    break;
                }
            }
            if(ck){
                answer++;
            }
        }
    }
    return answer;
}