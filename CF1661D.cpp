#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++){
        cin>>v[i];
    }
    long long ans = 0;
    ll sum = 0;
    ll num = 0;
    vector<ll> dif(n,0);
    for(ll i = n-1;i>=k-1;i--){
        v[i] -= sum;
        ll mv = (v[i]+k-1)/k;
        if(mv<0)mv = 0;
        dif[i-k+1] += mv;
        ans += mv;
        sum += mv*k;
        num += mv;
        v[i] -= mv*k;
        sum -= num;
        num -= dif[i];
    }
    ll add = 0;
    for(ll i = k-2;i>=0;i--){
        v[i] -= sum;
        add = max(add,(v[i]+i)/(i+1));
        sum -= num;
        num -= dif[i];
    }
    cout<<add+ans;
}
