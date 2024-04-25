#include <bits/stdc++.h>
using namespace std;

#define ll long long

int f(ll n){
    for(int i = 0;i<=32;i++){
        if((1LL<<i)>n)return i;
    }
    return INT_MAX;
}
void solve(){
    int n;
    cin>>n;
    vector<ll> v(n);
    ll big = INT_MIN;
    int ans = 0;
    for(int i = 0;i<n;i++){
        cin>>v[i];
        ans = max(ans,f(big-v[i]));
        big = max(big,v[i]);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
