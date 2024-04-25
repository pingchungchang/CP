#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n,c;
    cin>>n>>c;
    ll arr[n+1];
    for(int i = 1;i<=n;i++)cin>>arr[i];
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(int i =1 ;i<=n;i++){
        pq.push(i+arr[i]);
    }
    ll ans = 0;
    while(!pq.empty()&&pq.top()<=c){
        c -= pq.top();
        ans++;
        pq.pop();
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}