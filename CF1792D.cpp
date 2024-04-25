#include <bits/stdc++.h>
using namespace std;

const int mxn = 5e4+10;

int arr[mxn][11];
int pos[11];
int ans[mxn];
int n,m;

struct node{
    node* childs[11];
    node(){
        memset(childs,0,sizeof(childs));
    }
};
node* trie;

void clean(node* now){
    if(!now)return;
    for(auto &i:now->childs)clean(i);
    free(now);
    return;
}

void add(int id){
    auto now = trie;
    for(int i = 1;i<=m;i++){
        if(!now->childs[arr[id][i]])now->childs[arr[id][i]] = new node();
        now = now->childs[arr[id][i]];
    }
    return;
}

int getans(){
    node* now = trie;
    for(int i = 1;i<=m;i++){
        if(!now->childs[pos[i]])return i-1;
        now = now->childs[pos[i]];
    }
    return m;
}

void solve(){
    trie = new node();
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int k;
            cin>>k;
            arr[i][k] = j;
        }
        add(i);
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++)pos[arr[i][j]] = j;
        ans[i] = getans();
    }
    for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}