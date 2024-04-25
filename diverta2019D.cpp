#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
    ll k;
    cin>>k;
    ll ans = 0;
    for(ll i = 1;i*i<=k;i++){
        if(k%i == 0){
            ll j = k/i-1;
            if(j<=i)continue;
            if(k/j == i)ans += j;
        }
    }
    cout<<ans;
}
