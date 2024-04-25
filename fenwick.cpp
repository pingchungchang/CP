#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> bit(3*1e5+10,0LL);
ll n;

ll lowbit(ll x){
    return (x&(-x));
}
ll getval(ll pos){
    if(pos == 0)return 0LL;
    ll nxt = pos-lowbit(pos);
    return bit[pos]+getval(nxt);
}
void changeval(ll pos,ll val){
    bit[pos] += val;
    pos += lowbit(pos);
    if(pos>n)return;
    changeval(pos,val);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    ll q;
    cin>>q;
    vector<ll> v(n+1);
    for(ll i = 1;i<=n;i++){
        cin>>v[i];
        changeval(i,v[i]);
    }
    for(ll i = 0;i<q;i++){
        ll t;
        cin>>t;
        if(t == 1){
            ll a,b;
            cin>>a>>b;
            ll delta = b-v[a];
            v[a] = b;
            changeval(a,delta);
        }
        else{
            ll a,b;
            cin>>a>>b;
            cout<<getval(b)-getval(a-1)<<'\n';
        }
    }
}
