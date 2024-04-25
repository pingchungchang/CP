#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<ll,vector<ll>,less<ll>> pq;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    for(int i = 1;i<n;i++)pq.push(v[i]-v[i-1]);
    for(int i = 0;i<k-1;i++)pq.pop();
    ll ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }
    cout<<ans;
}
