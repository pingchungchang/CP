#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = 0;
    ll pre = s[0];
    ll cnt = 0;
    for(auto &i:s){
        if(i == pre)cnt++;
        else cnt = 1;
        pre = i;
        ans = (ans+pw(2,cnt-1))%mod;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}