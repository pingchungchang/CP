#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int digits[31] = {};
    ll n,k;
    cin>>n>>k;
    for(ll i = 0;i<n;i++){
        ll tmp;
        cin>>tmp;
        for(ll j = 0;j<=30;j++){
            if(((1LL<<j)&tmp) == 0)digits[j]++;
        }
    }
    ll ans = 0;
    for(ll i = 30;i>=0;i--){
        if(k>=digits[i]){
            k -= digits[i];
            ans ^= (1<<i);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    for(ll i = 0;i<t;i++)solve();
}
