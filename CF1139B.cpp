#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll t;
    cin>>t;
    vector<ll> v(t);
    for(ll i = 0;i<t;i++)cin>>v[i];
    ll big = INT_MAX;
    ll ans = 0LL;
    for(ll i = t-1;i>=0;i--){
        if(v[i]<big){
            big = v[i];
            ans += v[i];
        }
        else{
            ans += max(0LL,big-1);
            big = max(0LL,big-1);
        }
    }
    cout<<ans;
}
