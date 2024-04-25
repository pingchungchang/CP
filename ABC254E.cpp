#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<ll>> v;
ll bfs(ll tmp,ll t){
    set<ll> goneto;
    goneto.insert(tmp);
    queue<pair<ll,ll>> q;
    q.push(make_pair(tmp,t));
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        if(now.second<=0)continue;
        for(auto nxt:v[now.first]){
            if(goneto.find(nxt) != goneto.end())continue;
            goneto.insert(nxt);
            q.push(make_pair(nxt,now.second-1));
        }
    }
    ll total = 0;
    for(auto i:goneto)total += i+1;
    return total;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    v = vector<vector<ll>>(n);
    for(ll i = 0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll q;
    cin>>q;
    vector<ll> ans;
    for(ll i = 0;i<q;i++){
        ll x,k;
        cin>>x>>k;
        x--;
        cout<<bfs(x,k)<<'\n';
    }
}
