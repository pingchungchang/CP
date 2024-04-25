#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    map<ll,ll> mp;
    for(ll i = 0;i<t*2;i++){
        ll k;
        cin>>k;
        mp[k]++;
    }
    ll ans = 0;
    for(auto i:mp){
        ans = max(ans,i.second-t);
    }
    cout<<ans;
}
