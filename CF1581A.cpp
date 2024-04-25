#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9+7;
ll pw(ll a,ll b){
    ll ans = 1;
    while(b != 0){
        if((b&1)!= 0)ans = ans*a%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll inverse(ll a){
    return pw(a,mod-2);
}
void solve(){
    ll n;
    cin>>n;
    n*=2;
    ll ans = 1LL;
    while(n){
        if(n == 0)break;
        ans = (ans*n)%mod;
        n--;
    }
    cout<<ans*inverse(2)%mod<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
