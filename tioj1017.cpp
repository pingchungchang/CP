#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    for(ll asd = 0;asd<t;asd++){
        ll n;
        ll ans=0;
        cin>>n;
        ll arr[n];
        for(ll i =0;i<n;i++)cin>>arr[i];
        pair<ll,ll> ps[n];
        ps[0].first = arr[0];
        ps[n-1].second = arr[n-1];
        for(ll i =1;i<n;i++){
            ps[i].first = max(arr[i-1],ps[i-1].first);
            ps[n-1-i].second = min(arr[n-1-i+1],ps[n-1-i+1].second);
        }
        for(ll i =1;i<n-1;i++){
            if(arr[i]>ps[i].first&&arr[i]<ps[i].second) {
                   // cout<<i<<' ';
                    ans++;
            }
        }
        cout<<ans;
        if(asd!=t-1)cout<<'\n';
    }
}
