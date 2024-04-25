#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pll pair<ll,ll>

const int mxn = 2e5+10;
pll v[mxn];
ll ans = 0;
int n;
const ll all = (1<<26)-1;
void f(int k){
    vector<int> vv;
    for(int ii = 0;ii<n;ii++){
        auto i = v[ii];
        if((1<<k)&i.first)continue;
        vv.push_back(i.second);
    }
    map<ll,ll> mp;
    for(auto &i:vv){
        ans += mp[all^(1<<k)^i];
        mp[i]++;
    }
    return;
}
void solve(){
    cin>>n;
    map<ll,ll> mp;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        int cnt = 0,tmp = 0;
        for(auto &i:s){
            cnt|=(1<<(i-'a'));
            tmp ^= (1<<(i-'a'));
        }
        v[i] = {cnt,tmp};
    }
    for(int i = 0;i<26;i++)f(i);
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)solve();
}
