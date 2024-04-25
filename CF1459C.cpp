#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    while(b != 0){
        a %= b;
        swap(a,b);
    }
    return a;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    n = v.size();
    ll G = v.back()-v[0];
    for(auto i:v){
        G = gcd(G,i-v[0]);
    }
    /*
    for(auto i:mp){
        cout<<i.first<<' '<<i.second<<',';
    }
    */

    for(ll i = 0;i<m;i++){
        ll now;
        cin>>now;
        if(n == 1){
            cout<<v[0]+now<<' ';
            continue;
        }
        cout<<gcd(G,v[0]+now)<<' ';
    }
}
