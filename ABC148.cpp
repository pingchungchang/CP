#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin>>n;
    if(n&1){
        cout<<0;
        return 0;
    }
    ll ans = 0;
    for(ll i = 5;i<=n;i*=5){
        ans += n/(i*2);
    }
    cout<<ans;
}