#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin>>n;
    ll ans = 1e18;
    for(ll i = 1;i*i<=n;i++){
        if(n%i == 0){
            ans = min(ans,i+n/i-2);
        }
    }
    cout<<ans;
}