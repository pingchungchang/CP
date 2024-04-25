#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


const int mxn = 2e5+10;
ll n,c,d,arr[mxn];

bool f(ll k){
    priority_queue<pll,vector<pll>,greater<pll>> rest;
    priority_queue<ll,vector<ll>,less<ll>> pq;
    ll total = 0;
    for(int i = 0;i<n;i++)pq.push(arr[i]);
    for(int i = 0;i<d;i++){
        if(!pq.empty()){
            total += pq.top();
            rest.push({i+k,pq.top()});
            pq.pop();
        }
        while(!rest.empty()&&rest.top().fs<=i){
            pq.push(rest.top().sc);
            rest.pop();
        }
    }
    if(total>=c)return true;
    else return false;
}
void solve(){
    cin>>n>>c>>d;
    for(int i = 0;i<n;i++)cin>>arr[i];
    ll l = 0,r = 1e9+10;
    while(l != r){
        ll mid = (l+r+1)>>1;
        if(f(mid))l = mid;
        else r = mid-1;
    }
    if(f(l) == false)cout<<"Impossible\n";
    else if(r>=d)cout<<"Infinity\n";
    else cout<<l<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}