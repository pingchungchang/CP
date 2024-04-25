#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e3+10;
int n,m;
vector<int> paths1[mxn],paths2[mxn];
int matchx[mxn],matchy[mxn];
bool visy[mxn];
int cnt = 0;

bool dfs(int now){
    for(auto &i:paths1[now]){
        if(visy[i])continue;
        visy[i] = true;
        if(!matchy[i]||dfs(matchy[i])){
            matchy[i] = now;
            matchx[now] = i;
            return true;
        }
    }
    return false;
}
void solve(){
    for(int i = 0;i<=n;i++){
        paths1[i].clear();paths2[i].clear();
        matchx[i] = matchy[i] = 0;
    }
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths1[a].push_back(b);
        paths2[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        fill(visy,visy+i+n+1,false);
        if(dfs(i))ans++;
    }
    cout<<"Case #"<<++cnt<<":";
    cout<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n>>m){
        if(!n&&!m)return 0;
        solve();
    }
}