#include <bits/stdc++.h>
using namespace std;

struct node{
    vector<int> childs;
    int par;
    int link_top;
    node(){
        link_top = 0;
    }
};
map<int,vector<int>> tops;
vector<node> tree;
void dfs(int now,int top){
    //cout<<now<<' '<<top<<'\n';
    tops[top].push_back(now);
    if(tree[now].childs.size()>0)dfs(tree[now].childs[0],top);
    for(int i = 1;i<tree[now].childs.size();i++){
        dfs(tree[now].childs[i],tree[now].childs[i]);
    }
    return;
}
void solve(){
    while(!tops.empty())tops.erase(tops.begin());
    //cout<<tops.size()<<endl<<endl;
    int n;
    cin>>n;
    int root = 0;
    tree = vector<node>(n+1,node());
    for(int i = 1;i<=n;i++){
        cin>>tree[i].par;
        if(tree[i].par == i){
            root = i;
            continue;
        }
        tree[tree[i].par].childs.push_back(i);
    }
    dfs(root,root);
    cout<<tops.size()<<'\n';
    for(auto it:tops){
        cout<<it.second.size()<<'\n';
        for(auto i:it.second)cout<<i<<' ';
        cout<<'\n';
    }
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
