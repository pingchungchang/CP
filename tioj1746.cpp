#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 1e5+10;
vector<int> tree[mxn];
vector<int> jelly;
pii dp[mxn];
bool cycle[mxn];
int deg[mxn];
int dist[mxn];
int len2 = 0,len1 = 0;
bool vis[mxn];
int n,k;
int ans = mxn*2;

void dfs(int now,int fa){
    for(auto nxt:tree[now]){
        if(nxt == fa)continue;
        dist[nxt] = dist[now]+1;
        dfs(nxt,now);
    }
    return;
}
void dfs1(int now,int fa){
    vis[now] = true;
    jelly.push_back(now);
    for(auto nxt:tree[now]){
        if(!cycle[nxt])continue;
        if(vis[nxt])continue;
        if(nxt==fa)continue;
        if(nxt == jelly[0])continue;
        dfs1(nxt,now);
    }
    return;
}
void dfs2(int now,int fa){
    dp[now] = {0,0};
    for(auto nxt:tree[now]){
        if(cycle[nxt]||nxt == fa)continue;
        dfs2(nxt,now);
        if(dp[nxt].fs+1>dp[now].fs){
            swap(dp[now].fs,dp[now].sc);
            dp[now].fs = dp[nxt].fs+1;
        }
        else if(dp[nxt].fs+1>dp[now].sc)dp[now].sc = dp[nxt].fs+1;
    }
    ans = min(ans,(n-1)*2-len1+1-(dp[now].fs+dp[now].sc-1));
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    memset(dist,0,sizeof(dist));
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,1);
    int r1 = 0;
    for(int i = 1;i<=n;i++){
        if(dist[i]>dist[r1])r1 = i;
    }
    memset(dist,0,sizeof(dist));
    dfs(r1,r1);
    int r2 = 0;
    len1 = 0;
    for(int i = 1;i<=n;i++){
        if(dist[i]>dist[r2])r2 = i,len1 = dist[i];
    }
    if(k == 1){
        cout<<(n-1)*2-len1+1;
        return 0;
    }
    tree[r1].push_back(r2);
    tree[r2].push_back(r1);
    fill(cycle,cycle+n+1,true);
    queue<int> q;
    for(int i = 1;i<=n;i++){
        deg[i] = tree[i].size();
        if(deg[i] == 1)q.push(i);
    }
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        cycle[now] = false;
        for(auto nxt:tree[now]){
            deg[nxt]--;
            if(deg[nxt]==1)q.push(nxt);
        }
    }
    for(int i = 1;i<=n;i++){
        if(cycle[i]){
            dfs1(i,i);
            break;
        }
    }
    int s = jelly.size();
    for(int i = 0;i<s;i++)jelly.push_back(jelly[i]);
    // for(auto &i:jelly)cout<<i<<' ';cout<<endl;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
    for(int i = 0;i<jelly.size();i++){
        dfs2(jelly[i],jelly[i]);
        pq.push({-1+i,i});
        while(pq.top().sc<=i-s)pq.pop();
        // cout<<jelly[i]<<":"<<ans<<endl;
        ans = min(ans,(n-1)*2-len1+1-(dp[jelly[i]].fs-i+pq.top().fs));
        /*ans = min ans , dp[a]+dp[b]-1-(idx[b]-idx[a]) = dp[b]-idx[b] + dp[a]+idx[a]-1*/
        // cout<<jelly[i]<<":"<<pq.top().fs<<" "<<pq.top().sc<<' '<<dp[jelly[i]].fs<<' '<<dp[jelly[i]].sc<<":"<<(n-1)*2-len1+1-(dp[jelly[i]].fs-i+pq.top().fs)<<endl;
        pq.push({dp[jelly[i]].fs-1+i,i});
    }
    cout<<ans;
}