#include <bits/stdc++.h>
using namespace std;

#define ll long long
int k,n;
vector<ll> v;
bool f(ll now){
    ll sum = 0;
    ll ans = 0;
    for(auto i:v){
        if(i>=now)ans++;
        else sum += i;
    }
    if(ans+sum/now>=k)return true;
    return false;
}
int main(){
    cin>>n>>k;
    ll total = 0;
    v = vector<ll> (n);
    for(ll i = 0;i<n;i++){
        cin>>v[i];
        total += v[i];
    }
    ll l = 0,r = total;
    while(l != r){
        ll mid = (l+r+1     )/2;
        if((f(mid)))l = mid;
        else r = mid-1;
    }
    cout<<l;
}
