#include<iostream>
#include<vector>
using namespace std;
vector<int> Party[50];
int Parent[50];
vector<int> Truth;

int FindParent(int A){
    if(Parent[A]==A)return A;
    return Parent[A]=FindParent(Parent[A]);
}
void Union(int A,int B){

    A=FindParent(A);
    B=FindParent(B);
    Parent[B]=A;
}
int main(){
    int N,M;
    int answer=0;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        Parent[i]=i;
    }
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int person;
        cin>>person;
        Truth.push_back(person);
    }
    for(int i=0;i<M;i++){
        int number;
        cin>>number;

        for(int j=0;j<number;j++){
            int member;
            cin>>member;
            Party[i].push_back(member);
        }
    }
    for(int i=0;i<M;i++){
        for(int j=1;j<Party[i].size();j++){
            Union(Party[i][0],Party[i][j]);
        }
    }
    
    for(int i=0;i<M;i++){
        bool GoParty=true;
        answer++;
        for(int j=0;j<Party[i].size();j++){
            for(int k=0;k<Truth.size();k++){
                if(FindParent(Party[i][j])==FindParent(Truth[k])){
                    GoParty=false;
                    answer--;
                    break;
                }
            }
            if(!GoParty)break;
        }
    }
    cout<<answer<<"\n";
}