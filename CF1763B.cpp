#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
void solve(){
    ll n,k;
    cin>>n>>k;
    pll arr[n];
    for(auto &i:arr)cin>>i.fs;
    for(auto &i:arr)cin>>i.sc;
    multiset<ll> st;
    for(auto &i:arr)st.insert(i.sc);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    for(auto &i:arr)pq.push(i);
    ll total = 0;
    while(!pq.empty()&&k>0){
        total += k;
        while(!pq.empty()&&pq.top().fs<=total){
            st.erase(st.find(pq.top().sc));
            pq.pop();
        }
        if(!pq.empty())k -= *st.begin();
    }
    if(pq.empty())cout<<"YES\n";
    else cout<<"NO\n";
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}