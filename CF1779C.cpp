#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,m;
    cin>>n>>m;
    ll arr[n+1];
    for(int i = 1;i<=n;i++)cin>>arr[i];
    arr[0] = 0;
    ll ans= 0;
    ll total = 0,shift = 0;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i = 1;i<=m;i++)arr[i] += arr[i-1];
    // for(auto &i:arr)cout<<i<<' ';cout<<endl;
    for(int i = m;i>=1;i--){
        while(arr[i]+shift*2<arr[m]){
            shift -= pq.top();
            pq.pop();
            ans++;
        }
        pq.push(arr[i-1]-arr[i]);
    }

    total = shift = 0;
    while(!pq.empty())pq.pop();
    for(int i = m+1;i<=n;i++){
        pq.push(arr[i]);
        total += arr[i];
        while(total+shift*2<0){
            ans++;
            shift -= pq.top();
            pq.pop();
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}