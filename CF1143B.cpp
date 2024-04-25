#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll pw(ll a,ll b){
    ll ans = 1;
    while(b != 0){
        if((b&1) != 0)ans *= a;
        a *= a;
        b>>=1;
    }
    return ans;
}
ll cnt(ll now){
    string t = to_string(now);
    ll returns = 1;
    for(auto i:t)returns *= i-'0';
    return returns;
}
int main(){
    string s;
    cin>>s;
    ll ans = (s[0]-'0'-1)*pw(9,s.size()-1);
    for(ll i = 0;i<s.size();i++){
        ll tmp = stoll(s.substr(0,i+1)+string(s.size()-1-i,'9'));
        if(tmp>stoll(s)){
            ll k = stoll(s.substr(0,i+1));
            k--;
            tmp = stoll(to_string(k)+string(s.size()-1-i,'9'));
        }
//        cout<<tmp<<' ';
        if(tmp>stoll(s))continue;
        else ans = max(ans,cnt(tmp));
    }
    cout<<ans;
}
