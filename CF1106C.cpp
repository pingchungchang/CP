#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++)cin>>v[i];
    sort(v.begin(),v.end());
    ll ans = 0;
    for(int i = 0;i<n/2;i++){
        ans += (v[i]+v[n-1-i])*(v[i]+v[n-1-i]);
    }
    cout<<ans;
}
