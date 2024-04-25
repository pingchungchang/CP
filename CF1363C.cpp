#include <bits/stdc++.h>
using namespace std;

struct node{
    int dep;
    vector<int>childs;
    int par;
    node(){
        par = -1;
        dep = 0;
    }
};
int ans;
vector<node> tree;

void dfs(int now){
    if(tree[now].childs.size() == 1){
        ans += tree[now].dep%2;
        return;
    }
    for(auto nxt:tree[now].childs){
        if(nxt == tree[now].par)continue;
        tree[nxt].dep = tree[now].dep+1;
        tree[nxt].par = now;
        dfs(nxt);
    }
}
void solve(){
    ans = 0;
    int n,x;
    cin>>n>>x;
    tree = vector<node>(n+1,node());
    for(int i = 0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        tree[a].childs.push_back(b);
        tree[b].childs.push_back(a);
    }
    if(tree[x].childs.size() <= 1){
        cout<<"Ayush\n";
        return;
    }
    if((n-2)%2 == 0){
        cout<<"Ayush\n";
    }
    else cout<<"Ashish\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
