#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,p;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>p;
    ll ans =0;
    for(ll i =0;i<n;i++){
        ll k;
        cin>>k;
        if(k<p)ans++;
    }
    cout<<ans;
}
