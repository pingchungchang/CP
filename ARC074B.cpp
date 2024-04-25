#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    ll arr[n*3+1];
    for(int i = 1;i<=n*3;i++)cin>>arr[i];
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll total = 0;
    ll lef[n*3+1],rig[n*3+1];
    for(int i = 1;i<=n;i++){
        total += arr[i];
        pq.push(arr[i]);
    }
    lef[n] = total;
    for(int i = n+1;i<=n*3;i++){
        total += arr[i];
        pq.push(arr[i]);
        total -= pq.top();
        pq.pop();
        lef[i] = total;
    }
    while(!pq.empty())pq.pop();
    total = 0;
    for(int i = n*3;i>n*2;i--){
        total += arr[i];
        pq.push(-arr[i]);
    }
    rig[n*2+1] = total;
    for(int i = n*2;i>=1;i--){
        total += arr[i];
        pq.push(-arr[i]);
        total += pq.top();
        pq.pop();
        rig[i] = total;
    }
    ll ans = -1e18;
    for(int i = n;i<=n*2;i++){
        // cout<<i<<' '<<lef[i]<<' '<<rig[i+1]<<endl;
        ans= max(ans,lef[i]-rig[i+1]);
    }
    cout<<ans;
    return 0;
}