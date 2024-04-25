#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll f(string s,ll n){
    ll k = s.size()/n;
    string tmp;
    for(ll i = 0;i<k;i++)tmp += s.substr(0,n);
    if(tmp>s){
        tmp = "";
        ll tt = stoll(s.substr(0,n));
        tt--;
        for(ll i = 0;i<k;i++)tmp += to_string(tt);
    }
    return stoll(tmp);
}
void solve(){
    string s;
    cin>>s;
    ll ans = stoll(string(s.size()-1,'9'));
    for(ll i = 2;i<=s.size();i++){
        if(s.size()%i == 0){
            ans = max(ans,f(s,s.size()/i));
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
