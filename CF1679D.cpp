#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,k;
vector<vector<ll>> paths;
vector<ll> vals;
vector<ll> goneto;

void dfs(ll pos,ll val){
    goneto[pos] = -1;
    ll ans = 0LL;
    for(auto nxt:paths[pos]){
        if(vals[nxt]>val)continue;
        if(goneto[nxt] == -1){
            goneto[pos] = INT_MAX;
            return;
        }
        if(goneto[nxt] == 0){
            dfs(nxt,val);
        }
        ans = max(ans,goneto[nxt]);
    }
    goneto[pos] = ans+1;
    return;
}
bool f(ll now){
    goneto = vector<ll>(n+1,0LL);
    for(ll i = 1;i<=n;i++){
        if(vals[i]<=now&&goneto[i] == 0)dfs(i,now);
    }
    for(ll i = 1;i<=n;i++){
        if(goneto[i] >=INT_MAX)return true;
        else if(goneto[i]>=k)return true;
    }
    return false;
}
int main(){
    cin>>n>>m>>k;
    vals = vector<ll>(n+1);
    vector<ll>all;
    paths = vector<vector<ll>>(n+1);
    for(ll i = 1;i<=n;i++){
        cin>>vals[i];
        all.push_back(vals[i]);
    }
    for(ll i = 0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        paths[a].push_back(b);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    ll l = 0,r = all.size()-1;
    //cout<<'\n';
    while(l != r){
        ll mid = (l+r)/2;
        //cout<<all[mid]<<' '<<f(all[mid])<<'\n';
        if(f(all[mid]))r = mid;
        else l = mid+1;
    }
    if(f(all[l]) == false)cout<<-1;
    else cout<<all[l];
    return 0;
}
