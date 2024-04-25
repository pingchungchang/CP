#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll ans = 0;
    int n;
    cin>>n;
    priority_queue<ll,vector<ll>,less<ll>> pq;
    while(n--){
        int k;
        cin>>k;
        if(!k){
            if(!pq.empty()){
                ans += pq.top();
                pq.pop();
            }
        }
        else pq.push(k);
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