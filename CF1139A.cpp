#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
    ll n;
    string s;
    cin>>n>>s;
    ll ans = 0;
    for(ll i = 0;i<n;i++){
        if((s[i]-'0')%2 == 0){
            ans += i+1;
        }
    }
    cout<<ans;
}
