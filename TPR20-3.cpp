#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    ll pref[n+1];
    memset(pref,0LL,sizeof(pref));
    for(ll i = 1;i<=n;i++){
        cin>>pref[i];
        pref[i] += pref[i-1];
    }
    ll ans =0;
    for(ll i = 0;i<n;i++){
        for(ll j = i+1;j<=n;j++){
            if(pref[j]-pref[i]<=m)ans++;
        }
    }
    cout<<ans;
}
