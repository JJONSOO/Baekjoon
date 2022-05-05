#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include<iostream>
using namespace std;
class Node {
public:
    int value;
    int num;
    Node* left;
    Node* right;
    Node(const int& value,const int& num) : value(value),num(num) {left=NULL;right=NULL;}
};
vector<int>pre;
vector<int>post;
class BinarySearchTree {
private:
    Node* root;
    void _insert(Node* cursor,  int value, int num) {
        Node* parent;
        // cout<<cursor->value<<endl;
        // return;
        while (cursor->value>=0) {
            // cout<<cursor->value<<endl;
            parent = cursor;
            if (parent->value > value) {
                if(cursor->left==NULL){
                    break;}
                    
                cursor = cursor->left;
            }
            else {
                if(cursor->right==NULL){
                    break;}
                cursor = cursor->right;
            }
        }
        if (parent->value > value) {
            parent->left = new Node(value,num);
        }
        else if (parent->value < value) {
            parent->right = new Node(value,num);
        }

    }

    void _preorderTraversal(Node* cursor) {
        if (!cursor) {
                    // cout<<"없어"<<endl;

            return;
        }
        // cout<<"ehlo"<<endl;
        pre.push_back(cursor->num);
        this->_preorderTraversal(cursor->left);
        this->_preorderTraversal(cursor->right);
    }
    void _postorderTraversal(Node* cursor) {
        if (!cursor) {
                    // cout<<"없어"<<endl;

            return;
        }
        // cout<<"ehlo"<<endl;
        this->_postorderTraversal(cursor->left);
        this->_postorderTraversal(cursor->right);
        post.push_back(cursor->num);
    }
public:
    void insert( int value,int num) {
        if (!this->root) {
            this->root = new Node(value,num);
            return;
        }

        this->_insert(this->root, value,num);
    }

    void printpreorderTree() {

        this->_preorderTraversal(this->root);
    }
    void printpostorderTraversal() {

        this->_postorderTraversal(this->root);
    }


};
bool cmp(vector<int>a,vector<int>b){
    return a[1]>b[1];
}
int arr[1000];
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>>nodeinfos;
    for(int i=0;i<nodeinfo.size();i++){
        vector<int>tmp =nodeinfo[i];
        tmp.push_back(i+1);
        nodeinfos.push_back(tmp);
    }
    sort(nodeinfos.begin(),nodeinfos.end(),cmp);

    vector<vector<int>> answer;
    BinarySearchTree* bst = new BinarySearchTree();

    // bst->printTree();
    // cout<<nodeinfos[2][0]<<" "<<nodeinfos[2][2]<<endl;
    // bst->insert(nodeinfos[2][0],nodeinfos[2][2]);

    for(int i=0;i<nodeinfos.size();i++){
        bst->insert(nodeinfos[i][0],nodeinfos[i][2]);
    }
    bst->printpostorderTraversal();
    bst->printpreorderTree();
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}