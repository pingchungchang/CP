#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    int n;
    cin>>n;
    while(n--){
        ll k;
        cin>>k;
        pq.push(k);
    }
    ll total = 0;
    ll ans =0;
    while(!pq.empty()){
        total += pq.top();
        ans += total;
        pq.pop();
    }
    cout<<ans;
}