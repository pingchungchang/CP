#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second
const int mxn = 2e5+10;
int dsu[mxn],sz[mxn],val[mxn];
priority_queue<pii,vector<pii>,greater<pii>> paths[mxn];
int root(int k){
    return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

void onion(int a,int b){
    a = root(a),b = root(b);
    if(a == b)return;
    if(sz[a]<sz[b])swap(a,b);
    dsu[b] = a;
    sz[a] += sz[b];
    if(paths[a].size()<paths[b].size())swap(paths[a],paths[b]);
    while(!paths[b].empty()){
        if(root(paths[b].top().sc) != a)paths[a].push(paths[b].top());
        paths[b].pop();
    }
    return;
}
void clean(int n){
    for(int i = 1;i<=n;i++)while(!paths[i].empty())paths[i].pop();for(int i = 0;i<=n;i++)dsu[i] = sz[i] = 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        dsu[i] = i;
        sz[i] = 1;
    }
    for(int i = 1;i<=n;i++)cin>>val[i];
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        paths[a].push({val[b],b});
        paths[b].push({val[a],a});
    }
    queue<int> q;
    for(int i = 1;i<=n;i++)if(!val[i])q.push(i);
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        now = root(now);
        while(!paths[now].empty()&&val[paths[now].top().sc]<=sz[now]){
            auto tmp = paths[now].top().sc;
            paths[now].pop();
            onion(tmp,now);
            now = root(now);
        }
    }
    if(sz[root(1)] != n)cout<<"NO\n";
    else cout<<"YES\n";
    clean(n);
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}