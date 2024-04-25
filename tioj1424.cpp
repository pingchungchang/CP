#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    while(n--){
        ll k;
        cin>>k;
        pq.push(k);
    }
    ll total = 0;
    while(pq.size()>1){
        ll a = pq.top();pq.pop();
        ll b = pq.top();pq.pop();
        total += a+b;
        pq.push(a+b);
    }
    cout<<total;
}
