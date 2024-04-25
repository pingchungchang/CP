#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
bitset<mxn> vis;
vector<int> paths[mxn];
int e = 0,v = 0;

void dfs(int now){
    vis[now] = true;
    v++;
    e += paths[now].size();
    for(auto nxt:paths[now]){
        if(!vis[nxt])dfs(nxt);
    }
    return;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            e = v =0;
            dfs(i);
            e>>=1;
            // cout<<i<<":"<<e<<' '<<v<<endl;
            if(e != v){
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
    return 0;
}