#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans1 = 0,ans2 = 0;
    vector<ll> v(n);
    vector<ll> pref(n+1,0LL);
    for(ll i = 1;i<=n;i++){
        cin>>v[i-1];
        pref[i] = v[i-1];
        pref[i] += pref[i-1];
        if(i<k)ans1 = max(ans1,pref[i]);
        else ans1 = max(ans1,pref[i]-pref[i-k]);
    }
    if(k<=n){
        ans2 = k*(k-1)/2;
    }
    else{
        ans2 = (k-1)*n-n*(n-1)/2;
    }
    cout<<ans2+ans1<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
