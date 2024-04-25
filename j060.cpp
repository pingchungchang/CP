#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const int mxn = 505;
vector<int> g[mxn],st;
bool paths[mxn][mxn],visy[mxn];
int matchx[mxn],matchy[mxn],low[mxn],idx[mxn],gid[mxn],idcnt = 0,gcnt = 0;

void tarjan(int now){
    st.push_back(now);
    idx[now] = low[now] = ++idcnt;
    for(auto nxt:g[now]){
        if(gid[nxt])continue;
        if(!idx[nxt]){
            tarjan(nxt);
            low[now] = min(low[now],low[nxt]);
        }
        else{
            low[now] = min(low[now],idx[nxt]);
        }
    }
    if(low[now] == idx[now]){
        gcnt++;
        while(st.back() != now){
            gid[st.back()] = gcnt;
            st.pop_back();
        }
        gid[st.back()] = gcnt;
        st.pop_back();
    }
    return;
}
bool dfs(int now){
    for(int i = 1;i<=gcnt;i++){
        if(visy[i]||!paths[now][i])continue;
        visy[i] = true;
        if(!matchy[i]||dfs(matchy[i])){
            matchx[now] = i;
            matchy[i] = now;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i = 1;i<=n;i++){
        if(!idx[i])tarjan(i);
    }
    for(int i = 1;i<=n;i++){
        for(auto nxt:g[i]){
            if(gid[nxt] == gid[i])continue;
            paths[gid[i]][gid[nxt]]= true;
        }
    }
    //for(int i = 1;i<=n;i++)cout<<gid[i]<<' ';return 0;
    for(int asd = 0;asd<6;asd++)for(int i = 1;i<=n;i++)for(int j= 1;j<=n;j++)for(int k = 1;k<=n;k++)paths[j][k] = paths[j][k]||(paths[j][i]&&paths[i][k]);
    int ans = 0;
    for(int i = 1;i<=gcnt;i++){
        fill(visy,visy+gcnt+1,false);
        if(dfs(i))ans++;
    }
    cout<<gcnt-ans;
}
/*
6 5
1 2
3 2
2 4
2 5
5 1

*/
