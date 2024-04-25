#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e4+10;
vector<int> paths[mxn];
int low[mxn],idx[mxn];
bool iscut[mxn];
int cnt = 0;
void dfs(int now,int par){
    idx[now] = low[now] = ++cnt;
    int c = 0;
    for(auto nxt:paths[now]){
        if(nxt == par)continue;
        if(!idx[nxt]){
            c++;
            dfs(nxt,now);
            low[now] = min(low[now],low[nxt]);
            if(par != now&&low[nxt]>=idx[now])iscut[now] = true;
        }
        else{
            low[now] = min(low[now],idx[nxt]);
        }
    }
    if(now == par&&c>1)iscut[now] = true;
}

void solve(){
    int n,m;
    cnt = 0;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs(1,1);
    vector<int> ans;
    for(int i = 1;i<=n;i++){
        if(iscut[i])ans.push_back(i);
        paths[i].clear();
        iscut[i] = 0;
        idx[i] = low[i] = 0;
    }
    if(ans.empty())cout<<"0\n0\n";
    else{
        cout<<ans.size()<<'\n';
        for(auto &i:ans)cout<<i<<' ';cout<<'\n';
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}