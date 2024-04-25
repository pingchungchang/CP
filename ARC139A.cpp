#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i =0;i<n;i++)cin>>v[i];
    ll now = 0;
    ll val = 0;
    for(auto i:v){
        for(ll j = 0;j<i;j++){
            if((val&(1LL<<j))!= 0){
                val ^= (1LL<<j);
            }
        }
        val += (1LL<<i);
        if((val&(1LL<<i)) == 0)val += (1LL<<i);
    }
    cout<<val;
    return 0;
}
