#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
    Node* parent;
    long long distance;
    vector<Node*> childs;
    long long id;
} Node;
long long finddist(Node* root,long long& ans){
    long long x =0;
    for(long long i = 0;i<root->childs.size();i++){
        x = max(x,finddist(root->childs[i],ans)+1);
    }
    ans += x;
    // cout<<root->id<<' '<<x<<endl;
    return x;
}
int main(){
    long long k;
    cin>>k;
    Node* root;
    unordered_map<long long,Node*>m;
    for(long long i = 1;i<=k;i++){
        long long n;
        cin>>n;
        Node* now = new Node;
        now->parent = nullptr;
        now->id = i;
        now->distance = -1;
        if(m.count(i) != 0){
            now = m[i];
        }
        else m[i] = now;
        for(long long j = 0;j<n;j++){
            long long x;
            cin>>x;
            Node* whatever = new Node;
            whatever->distance = -1;
            whatever->id = x;
            if(m.count(x) != 0){
                whatever = m[x];
            }
            else m[x] = whatever;
            whatever->parent = now;
            now->childs.push_back(whatever);
        }
    }
    root = m[1];
    while(root->parent != nullptr)root = root->parent;
    cout<<root->id<<endl;
    long long ans = 0;
    finddist(root,ans);
    cout<<ans;
}