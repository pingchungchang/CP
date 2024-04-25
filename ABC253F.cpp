#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,q;
ll idx = 1;
vector<vector<pair<ll,ll>>>  segtree;
void addval(ll now,ll l,ll r,ll s,ll e,ll v){
    //cout<<s<<' '<<e<<' '<<l<<' '<<r<<endl;
    if(s<=l&&e>=r){
        segtree[now].push_back(make_pair(idx,v+segtree[now].back().second));
        return;
    }
    ll mid = (l+r)/2;
    if(mid>=e)addval(now*2+1,l,mid,s,e,v);
    else if(mid+1<=s)addval(now*2+2,mid+1,r,s,e,v);
    else{
        addval(now*2+1,l,mid,s,e,v);
        addval(now*2+2,mid+1,r,s,e,v);
    }
    return;
}
ll getval(ll now,ll l,ll r,ll p,ll t){
    ll ans = 0LL;
    //cout<<l<<' '<<r<<' '<<p<<endl;
    ll pos = upper_bound(segtree[now].begin(),segtree[now].end(),make_pair(t,0LL))-segtree[now].begin()-1;
    if(l == r)return  segtree[now].back().second-segtree[now][pos].second;
    ll mid = (l+r)/2;
    if(mid>=p)return segtree[now].back().second-segtree[now][pos].second+getval(now*2+1,l,mid,p,t);
    else return segtree[now].back().second-segtree[now][pos].second+getval(now*2+2,mid+1,r,p,t);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    segtree = vector<vector<pair<ll,ll>>>(m*4,vector<pair<ll,ll>>(1,make_pair(-1LL,0LL)));
    vector<pair<ll,ll>> tag(n,make_pair(0LL,0LL));
    for(ll i = 0;i<q;i++){
        ll t;
        cin>>t;
        if(t == 1){
            ll s,e,v;
            cin>>s>>e>>v;
            addval(0,0,m-1,s-1,e-1,v);
            idx++;
        }
        else if(t == 2){
            ll p,x;
            cin>>p>>x;
            tag[p-1] = make_pair(idx,x);
            idx++;
        }
        else{
            ll r,c;
            cin>>r>>c;
            cout<<tag[r-1].second + getval(0,0,m-1,c-1,tag[r-1].first)<<'\n';
        }
    }
    return 0;
}
