#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin>>n;
    ll a[n];
    priority_queue<ll,vector<ll>,less<ll>> pq;
    for(ll i =0;i<n;i++){
        cin>>a[i];
    }
    for(ll i =0;i<n;i++){
        ll k;
        cin>>k;
        pq.push(k);
    }
    ll ans =0;
    sort(a,a+n);
    while(!pq.empty()){
        ll now = pq.top();
        pq.pop();

    }
}
