#include <bits/stdc++.h>
using namespace std;


#define ll long long
const ll p = 1e9+7;
ll pw(ll a,ll b,ll mod){
    ll ans = 1LL;
    while(b > 0){
        if((b&1))ans *= a;
        a*= a;
        b>>=1;
        a%= mod;
        ans %= mod;
    }
    return ans;
}
void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll x = pw(b,c,p-1);
    cout<<pw(a,x,p)<<'\n';
    return;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
