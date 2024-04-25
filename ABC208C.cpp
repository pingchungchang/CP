#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a;
    ll n;
    cin>>a>>n;
    vector<pair<ll,ll>> v(a);
    for(ll i =0;i<a;i++){
        ll x;
        cin>>x;
        v[i].first = x;
        v[i].second = 0;
    }
    vector<pair<ll,ll>> cop = v;
    sort(v.begin(),v.end());
    ll now = n/a;
    n -= now*a;
    ll limit;
    if(n ==0)limit = -1;
    else limit = v[n-1].first;
    for(ll i =0;i<a;i++){
        if(cop[i].first<=limit)cout<<now+1;
        else cout<<now;
        cout<<'\n';
    }

}
