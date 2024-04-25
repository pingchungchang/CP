#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    int n,m;
    cin>>n>>m;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    while(n--){
        ll k;
        cin>>k;
        pq.push(k);
    }
    while(m--){
        int x;
        cin>>x;
        pq.pop();
        pq.push(x);
    }
    ll total = 0;
    while(!pq.empty()){
        if(pq.top()>0)total += pq.top();
        pq.pop();
    }
    cout<<total<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}