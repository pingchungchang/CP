#include <bits/stdc++.h>
using namespace std;

#define ll long long
string s;

bool isprime(ll n){
    if(n == 0||n == 1)return false;
    for(ll i = 2;i<=sqrt(n);i++){
        if(n%i == 0)return false;
    }
    return true;
}
void solve(){
    vector<ll>ans;
    string now = "0";
    for(auto i:s){
        now += i;
        if(isprime(stoll(now))){
            ans.push_back(stoll(now));
            now = "0";
        }
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans)cout<<i<<'\n';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>s){
        solve();
    }
}


/*
1359376716
2359837607
8888888819
8888888809
8765432107
8765412107
*/
