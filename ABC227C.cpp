#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    for(ll i = 1;i*i*i<=n;i++){
        for(ll j = i;j*j*i<=n;j++){
            ans += max(0LL,n/i/j-j+1);
        }
    }
    cout<<ans;
}
