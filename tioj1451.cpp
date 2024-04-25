#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5+10;
vector<int> paths[mxn],dag[mxn];
int idx[mxn],low[mxn],gid[mxn],deg[mxn];
int cnt = 0,gcnt = 0;
vector<int> st;

void dfs(int now){
    idx[now] = low[now] = ++cnt;
    st.push_back(now);
    for(auto nxt:paths[now]){
        if(idx[nxt]){
            if(gid[nxt])continue;
            low[now] = min(low[now],idx[nxt]);
        }
        else{
            dfs(nxt);
            low[now] = min(low[now],low[nxt]);
        }
    }
    if(low[now] == idx[now]){
        gcnt++;
        while(st.back() != now){
            gid[st.back()] = gcnt;
            st.pop_back();
        }
        gid[now] = gcnt;
        st.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
    }
    for(int i =1;i<=n;i++){
        if(!idx[i])dfs(i);
    }
    for(int i = 1;i<=n;i++){
        for(auto nxt:paths[i]){
            if(gid[i] == gid[nxt])continue;
            dag[gid[i]].push_back(gid[nxt]);
            deg[gid[nxt]]++;
        }
    }
    int ans = 0;
    for(int i = 1;i<=gcnt;i++){
        if(!deg[i])ans++;
    }
    cout<<ans;
}