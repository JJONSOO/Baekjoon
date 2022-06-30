#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle.at(i).size();j++){
            if(j==0){
                triangle.at(i).at(0)+=triangle.at(i-1).at(0);
            }
            else if(j==triangle.at(i).size()-1){
                triangle.at(i).at(triangle.at(i).size()-1)+=triangle.at(i-1).at(triangle.at(i-1).size()-1);
            }
            else{
                triangle.at(i).at(j)+=max(triangle.at(i-1).at(j-1),triangle.at(i-1).at(j));
            }
        }   
    }
    for(int i=0;i<triangle.at(triangle.size()-1).size();i++){
        if(triangle.at(triangle.size()-1).at(i)>answer)
            answer=triangle.at(triangle.size()-1).at(i);
    }
    return answer;
}