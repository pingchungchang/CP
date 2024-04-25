#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll ans = 0;
    ll sum = 0;
    for(ll i = 0;i<n;++i){
        cin>>v[i];
        sum += v[i];
    }
    for(ll i = 0;i<n;i++){
        ans += (n-1)*v[i]*v[i];
        ans -= v[i]*(sum-v[i]);
    }
    cout<<ans;
}
