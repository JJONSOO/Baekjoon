    #include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>
    using namespace std;

    string solution(string new_id) {
        string answer = "";
        //1단계
        for(int i=0;i<new_id.length();i++){
            new_id[i]=tolower(new_id[i]);
        }
        //2단계
        cout<<new_id<<endl;
        string tmp="";
        for(int i=0;i<new_id.length();i++){
        if(new_id[i]=='.'||new_id[i]=='_'||new_id[i]=='-'){
            tmp+=new_id[i];
        }
        // cout<<new_id[i]-'0'<<endl;
        else if(new_id[i]-'0'>=0&&new_id[i]-'0'<=9){
            tmp+=new_id[i];
        }
        else if(new_id[i]-'a'>=0&&new_id[i]-'a'<=25){
            tmp+=new_id[i];
        }
        }
        new_id=tmp;
        cout<<new_id<<endl;
        //3단계
        for(int i=0;i<new_id.length()-1;i++){
            if(new_id[i]=='.'&&new_id[i+1]=='.'){
                new_id=new_id.substr(0,i+1)+new_id.substr(i+2);
                i=-1;
            }
        }
        cout<<new_id<<endl;
        //4단게
        if(new_id[0]=='.')
            new_id=new_id.substr(1);
        if(new_id[new_id.length()-1]=='.')
            new_id=new_id.substr(0,new_id.length()-1);
        cout<<new_id<<endl;
        //5단계
        if(new_id.length()==0)
            new_id="a";
        cout<<new_id<<endl;
        //6단계
        if(new_id.length()>=16){
            new_id=new_id.substr(0,15);
            if(new_id[14]=='.')
                new_id=new_id.substr(0,14);
        }
        cout<<new_id<<endl;
        //7단계
        if(new_id.length()==2){
            new_id=new_id+new_id[1];
        }
        if(new_id.length()==1){
            new_id=new_id+new_id[0];
            new_id=new_id+new_id[0];
        }
        cout<<new_id<<endl;
        return new_id;
    }