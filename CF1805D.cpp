#include <bits/stdc++.h>
using namespace std;

const int mxn = 1e5+10;
int dist[mxn];
vector<int> paths[mxn];

void dfs(int now,int par,int d){
    for(auto nxt:paths[now]){
        if(nxt == par)continue;
        dist[nxt] = max(dist[nxt],d+1);
        dfs(nxt,now,d+1);
    }
    return;
}
void solve(){
    int n;
    cin>>n;
    fill(dist,dist+n+1,0);
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs(1,1,0);
    int r1 = 0,d = 0;
    for(int i = 1;i<=n;i++){
        if(dist[i]>d)d = dist[i],r1 = i;
    }
    fill(dist,dist+n+1,0);
    dfs(r1,r1,0);
    d = 0,r1 = 0;
    for(int i = 1;i<=n;i++){
        if(dist[i]>d)r1 = i,d = dist[i];
    }
    dfs(r1,r1,0);
    // for(int i = 1;i<=n;i++)cout<<dist[i]<<' ';cout<<endl;
    int ans[n+1] = {};
    for(int i = 1;i<=n;i++){
        ans[dist[i]+1]++;
    }
    int pre = 1;
    for(int i = 1;i<=n;i++){
        pre += ans[i];
        cout<<min(pre,n)<<' ';
    }
    cout<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)solve();
}