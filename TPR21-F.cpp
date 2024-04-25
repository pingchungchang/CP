#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,b,l;
    cin>>l>>b>>n;
    vector<ll> v(n);
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        cin>>v[i];
        sum += v[i];
    }
    ll t = 0;
    while(sum<=l){
        sum += v[t%n];
        v.push_back(v[t%n]);
        t++;
    }
    for(auto i:v)cout<<i<<' ';cout<<endl;
    for(ll i = 1;i<v.size();i++){
        v[i] += v[i-1];
    }
    ll ans = 0;
    ll now = 0;
    while(now+b< l){
        ans ++;
        ll pos = --upper_bound(v.begin(),v.end(),now+b)-v.begin();
        now = v[pos];
        cout<<now<< endl;
    }
    cout<<ans;
}
