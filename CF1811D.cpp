#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mxn = 48;
ll fib[mxn];

void solve(){
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> h,w;
    x--,y--;
    for(int i = 1;i<=n;i++){
        if(i&1)w.push_back(fib[i]);
        else h.push_back(fib[i]);
    }
    if(!h.empty()&&h.back()>w.back())swap(h,w);
    for(int i = h.size()-1;i>=0;i--){
        if(x>=h[i])x -= h[i];
    }
    for(int i = w.size()-1;i>=0;i--){
        if(y>=w[i])y -= w[i];
    }
    if(x == 0&&y == 0)cout<<"YES\n";
    else cout<<"NO\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fib[0] = fib[1] = 1;
    for(ll i = 2;i<mxn;i++)fib[i] = fib[i-1]+fib[i-2];
    int t;
    cin>>t;
    while(t--)solve();
}