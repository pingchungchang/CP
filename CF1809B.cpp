#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll f(ll k){
    if(k&1)return 4LL*((k+1)/2*(k+1)/2);
    else return 1LL+8LL*(k/2+1)*(k/2)/2;
}

void solve(){
    ll n;
    cin>>n;
    ll l = 0,r = 1e9;
    while(l != r){
        ll mid = (l+r)>>1;
        if(f(mid)>=n)r = mid;
        else l = mid+1;
    }
    cout<<l<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}