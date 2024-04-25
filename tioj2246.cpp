#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
map<pll,ll> mp;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,r;
    cin>>n>>r;
    vector<pll> v;
    while(n--){
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
        for(int dx = -r;dx<=r;dx++){
            for(int dy = -r;dy<=r;dy++){
                if(dx*dx+dy*dy<=r*r){
                    mp[{x+dx,y+dy}]++;
                }
            }
        }
    }
    ll ans = 0;
    for(auto &i:mp)if(i.sc&1)ans++;
    cout<<ans;
}