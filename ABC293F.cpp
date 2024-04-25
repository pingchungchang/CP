#include <bits/stdc++.h>
using namespace std;

#define ll __int128_t
#define int long long

ll gettotal(ll k,ll b){
    ll p = 1;
    ll total = 0;
    while(b){
        if(p>1e18)return 1e19;
        if(b&1)total += p;
        p *= k;
        b>>=1;
    }
    return total;
}
ll calc(ll tar,int b){
    ll l = 2,r = 1e18;
    while(l != r){
        ll mid = (l+r)>>1;
        int tb = b;
        if(gettotal(mid,tb)>=tar)r = mid;
        else l = mid+1;
    }
    if(gettotal(l,b) != tar)return 0;
    else return l;
}
bool check(ll tar,ll k){
    while(tar){
        if(tar%k != 1&&tar%k != 0)return false;
        tar /=k;
    }
    return true;
}
void solve(){
    int k;
    cin>>k;
    set<ll> st;
    for(int i = 1;i<(1<<9);i++){
        int tmp;
        if(tmp = calc(k,i))st.insert(tmp);
    }
    for(ll i = 2;i<=100;i++)if(check(k,i))st.insert(i);
    cout<<st.size()<<'\n';
    // for(auto &i:st)cout<<(long long)i<<',';cout<<'\n';
    return;
}
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}