#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n;
    cin>>n;
    ll ans = 0LL;
    for(ll i = 1;i<=sqrt(n);i++){
        if(stoll(to_string(i)+to_string(i))<=n)ans++;
    }
    cout<<ans;
}
