#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
void solve(){
    int n,k;
    cin>>n>>k;
    pll arr[n];
    for(auto &i:arr)cin>>i.fs>>i.sc;
    sort(arr,arr+n);
    priority_queue<ll,vector<ll>,less<ll>> pq;
    for(int i = 0;i<k;i++)pq.push(arr[i].sc);
    ll ans = arr[k-1].fs+pq.top();
    for(int i = k;i<n;i++){
        pq.push(arr[i].sc);
        pq.pop();
        ans = min(ans,arr[i].fs+pq.top());
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