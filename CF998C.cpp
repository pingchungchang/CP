#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n,x,y;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    ll g = 0;
    for(int i = 1;i<s.size();i++){
        if(s[i] == '0'&&s[i] != s[i-1])g++;
    }
    if(s[0] == '0')g++;
    ll ans = LONG_LONG_MAX;
    for(ll i = 0;i<g;i++){
        ans = min(ans,i*x+y*(g-i));
    }
    if(g == 0)cout<<0;
    else cout<<ans;
}
//00000
//010101010101
