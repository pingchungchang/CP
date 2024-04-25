#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
ll pw(ll a,ll b){
    ll re= 1;
    while(b){
        if(b&1)re = re*a%mod;
        b>>=1;
        a = a*a%mod;
    }
    return re;
}
ll inv(ll k){
    return pw(k,mod-2);
}
const int mxn = 2e5+10;
vector<int> paths[mxn];
bitset<mxn> del;
int deg[mxn];

void dfs(int now){
    del[now] = true;
    for(auto nxt:paths[now]){
        if(!del[nxt])dfs(nxt);
    }
    return;
}
bool flag = true;
void dfs1(int now){
    // cout<<now<<' '<<deg[now]<<",";
    deg[now]--;
    del[now] = true;
    for(auto nxt:paths[now]){
        if(del[nxt])continue;
        deg[nxt]--;
        if(deg[nxt] == 0)flag = false;
        else if(deg[nxt] == 1)dfs1(nxt);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        paths[a].push_back(b);
        paths[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(paths[i].size() == 0){
            cout<<"0";
            return 0;
        }
    }
    for(int i = 1;i<=n;i++){
        if(deg[i] == 1){
            dfs1(i);
            // cout<<endl;
        }
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    ll ans = 1;
    // for(int i = 1;i<=n;i++){
        // if(!del[i])cout<<i<<',';
    // }
    for(int i = 1;i<=n;i++){
       if(!del[i]&&deg[i] != 2){
            cout<<0;
            return 0;
        }
        else if(!del[i]){
            dfs(i);
            ans = ans*2%mod;
        }
    }
    assert(ans != 1);
    cout<<ans;
}