#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
int dsu[mxn];
int root(int k){
    return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
    dsu[root(a)] = root(b);
    return;
}

int main(){
    int n;
    cin>>n;
    int arr[n+1] = {};
    for(int i= 1;i<=n;i++)cin>>arr[i];
    bool vis[n+1] = {},cycle[n+1] = {};
    int deg[n+1] = {};
    vector<vector<int>> paths(n+1);
    for(int i = 1;i<=n;i++){
        paths[i].push_back(arr[i]);
        deg[arr[i]]++;
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(!deg[i])q.push(i);
    }
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        vis[now] = true;
        for(auto nxt:paths[now]){
            deg[nxt]--;
            if(!deg[nxt])q.push(nxt);
        }
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++)if(!vis[i])cnt++;
    cout<<cnt;
}
/*
1 2 3
3 1 2

1 2 3 4
1 2 3 4

*/