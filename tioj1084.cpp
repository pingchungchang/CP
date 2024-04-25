#include <bits/stdc++.h>
using namespace std;

int m;
int paths[505][505] = {};
int deg[505] = {};
int n = 501;
vector<int> ans;
void dfs(int now){
    for(int i = 0;i<n;i++){
        if(paths[now][i]){
            paths[now][i]--;
            paths[i][now]--;
            deg[i]--;
            deg[now]--;
            dfs(i);
            i--;
        }
    }
    ans.push_back(now);
}
void solve(){
    memset(paths,0,sizeof(paths));
    memset(deg,0,sizeof(deg));
    ans = {};
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a][b]++;
        paths[b][a]++;
        deg[a]++;
        deg[b]++;
    }
    vector<int> odd;
    int smallest = -1;
    for(int i = 0;i<n;i++){
        if(deg[i]%2 == 1)odd.push_back(i);
        else if(smallest == -1&&deg[i] != 0)smallest = i;
    }
    if(odd.size() != 0){
        dfs(odd[0]);
    }
    else{
        dfs(smallest);
    }
    for(auto it  = ans.rbegin();it != ans.rend();it++)cout<<*it<<'\n';
    if(ans.size() != m+1)cout<<deg[-1];
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>m){
        if(m == 0)return 0;
        solve();
    }
}
