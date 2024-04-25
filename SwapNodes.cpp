#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Node{
    public:
        Node* left;
        Node* right;
        int value;
        int level;
        Node(int a,int b){
            value = a;
            level = b;
            left = nullptr;
            right = nullptr;
        }
};
void dfs(Node* root){
    if(root != nullptr){
        dfs(root->left);
        cout<<root->value<<' ';
        dfs(root->right);
    }
}
int main(){
    int nums;
    cin>>nums;
    queue<Node*> q;
    Node alpha(1,1);
    Node* root = &alpha;
    unordered_map<int,vector<Node*>> leveltonode;
    q.push(root);
    while(!q.empty()){
        leveltonode[q.front()->level].push_back(q.front());
        int l,r;
        cin>>l>>r;
        if(l !=-1){
            Node k(l,q.front()->level+1);
            Node* kptr = &k;
            q.front()->left = kptr;
            q.push(kptr);
        }
        if(r != -1){
            Node jprum(r,q.front()->level+1);
            Node* j = &jprum;
            q.front()->right = j;
            q.push(j);
        }
        q.pop();
    }
    dfs(root);
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        int targetlevel;
        cin>>targetlevel;
        for(int i = 0;i<leveltonode[targetlevel].size();i++){
            Node* originalleft = leveltonode[targetlevel][i]->left;
            leveltonode[targetlevel][i]->left = leveltonode[targetlevel][i]->right;
            leveltonode[targetlevel][i]->right = originalleft;
        }
        dfs(root);
    }
}
