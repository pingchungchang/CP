#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)cin>>v[i];
    vector<pll> dp1(n,make_pair(-1,-1));
    vector<pll> dp2(n,make_pair(-1,-1));
    if(v[0] == x)dp1[0] = make_pair(0,0);
    if(v[0] == y)dp2[0] = make_pair(0,0);

    ll bigger = -1;
    if(v[0]>x)bigger = 0;
    for(ll i = 1;i<n;i++){
        if(v[i]>x){
            bigger = i;
            continue;
        }
        if(v[i] == x){
            dp1[i] = make_pair(bigger+1,i);
        }
        else{
            dp1[i] = dp1[i-1];
        }
    }

    ll smaller = -1;
    if(v[0]<y)smaller = 0;
    for(ll i = 1;i<n;i++){
        if(v[i]<y){
            smaller = i;
            continue;
        }
        if(v[i] == y){
            dp2[i] = make_pair(smaller+1,i);
        }
        else{
            dp2[i] = dp2[i-1];
        }
    }

    //for(auto i:dp1)cout<<i.fs<<','<<i.sc<<' ';cout<<endl;
    //for(auto i:dp2)cout<<i.fs<<','<<i.sc<<' ';cout<<endl;
    ll ans = 0;

    for(ll i = 0;i<n;i++){
        if(dp1[i].fs == -1||dp2[i].fs == -1)continue;
        pll a = dp1[i];
        pll b = dp2[i];
        if(a.fs>b.sc||b.fs>a.sc)continue;
        ans += min(a.sc,b.sc)-max(a.fs,b.fs)+1;
    }
    cout<<ans;
}
