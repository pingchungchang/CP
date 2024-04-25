#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll> mp;
ll f(ll n){
    if(n == 0)return 1;
    if(mp[n] != 0)return mp[n];
    else return mp[n] = f(n/2)+f(n/3);
}
int main(){
    ll n;
    cin>>n;
    cout<<f(n);
}
