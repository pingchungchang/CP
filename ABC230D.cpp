#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,d;
    cin>>n>>d;
    vector<pair<ll,ll>> v(n);
    for(ll i = 0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v[i] = make_pair(a,b);
    }
    sort(v.begin(),v.end());
    ll rhit = INT_MAX;
    ll ans = 0;
    for(ll i = n-1;i>=0;i--){
        if(rhit<=v[i].second){
            continue;
        }
        else{
            ans++;
            rhit = v[i].first-d+1;
        }
    }
    cout<<ans;
}