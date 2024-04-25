#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> two,five;

inline ll cnt(ll k){
    if(k == 0)return 0;
    ll re = 0;
    while(k%10 == 0){
        re++;
        k/=10;
    }
    return re;
}
void solve(){
    ll n,m;
    cin>>n>>m;
    ll ans = n;
    for(ll &i:two)for(ll &j:five){
        ll tmp = n*(m/(i*j))*(i*j);
        ll k = tmp;
        if(cnt(ans)<cnt(k))ans = k;
        else if(cnt(ans) == cnt(k))ans = max(ans,k);
    }
    cout<<ans<<'\n';
    return; 
}
int main(){
    for(int i = 0;i<30;i++)two.push_back(1LL<<i);
    for(ll i = 1;i<=1e9;i*=5)five.push_back(i);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}