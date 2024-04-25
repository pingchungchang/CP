#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9+7;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
ll inv(ll k){
    return pw(k,mod-2);
}
void solve(){
    ll n;
    cin>>n;
    ll total = n*(n+1)%mod*(2*n+1)%mod*inv(6)%mod*2%mod;
    total = total+mod-(n*(n+1)/2%mod);
    cout<<2022LL*total%mod<<'\n';
    //sum(i*i-i)
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
