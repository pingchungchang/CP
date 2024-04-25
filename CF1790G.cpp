#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5+10;
vector<int> paths[mxn];
bool token[mxn],bonus[mxn];
int dist[mxn];
int cnt[mxn];
void dfs2(int now,int c){
    cnt[now] = c;
    for(auto nxt:paths[now]){
        if(cnt[nxt] == -1){
            dfs2(nxt,c);
        }
    }
    return;
}
int dfs(int now){
    int c = 0;
    if(bonus[now])c++;
    cnt[now] = -1;
    for(auto nxt:paths[now]){
        if(cnt[nxt])continue;
        if(bonus[nxt])c += dfs(nxt);
    }
    return c;
}

int solve(){
    int n,m;
    cin>>n>>m;
    fill(token,token+n+1,false);fill(bonus,bonus+n+1,false);fill(dist,dist+n+1,0);
    fill(cnt,cnt+n+1,0);
    int ta,tb;
    cin>>ta>>tb;
    while(ta--){
        int k;
        cin>>k;
        token[k] = true;
    }
    while(tb--){
        int k;
        cin>>k;
        bonus[k] = true;
    }
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    bool flag = false;
    if(token[1])flag = true;
    for(auto nxt:paths[1]){
        if(token[nxt])flag = true;
    }
    pair<int,int> shortest = {mxn,-1};
    queue<int> q;
    q.push(1);
    int dist[n+1] = {};
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(auto nxt:paths[now]){
            if(nxt == 1)continue;
            if(!dist[nxt]){
                dist[nxt] = dist[now]+1;
                if(bonus[nxt])q.push(nxt);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        if(dist[i]&&token[i]){
            shortest = min(shortest,make_pair(dist[i],i));
        }
    }
    token[shortest.second] = false;
    for(int i = 1;i<=n;i++){
        if(bonus[i]&&!cnt[i])dfs2(i,dfs(i));
    }
    long long total = 0;
    for(int i = 1;i<=n;i++){
        if(token[i]){
            int big = 0;
            for(auto nxt:paths[i]){
                big = max(big,cnt[nxt]);
            }
            if(big>1)big = mxn;
            total += big;
        }
    }
    // cout<<total<<','<<shortest.first<<'\n';
    if(total>=shortest.first-1&&shortest.first<mxn)cout<<"YES\n";
    else if(flag)cout<<"YES\n";
    else cout<<"NO\n";
    for(int i = 0;i<=n;i++)paths[i].clear();
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}