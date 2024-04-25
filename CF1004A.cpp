#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,d;cin>>n>>d;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)cin>>v[i];
    ll ans = 2;
    for(ll i = 1;i<n;i++){
        if(v[i]-v[i-1]>d*2)ans += 2;
        else if(v[i]-v[i-1] == d*2)ans++;
    }
    cout<<ans;

}
