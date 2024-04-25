#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second

ll start;
void solve(){
    ll n,m;
    cin>>n>>m;
    map<ll,ll> mp;
    for(ll i = 0;i<n;i++){
        ll k;
        cin>>k;
        mp[k]++;
    }
    vector<pair<ll,ll>> bad(m*2);
    for(ll i = 0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        bad[i*2] = make_pair(a,b);
        bad[i*2+1] = make_pair(b,a);
    }
    sort(bad.begin(),bad.end());
    vector<vector<ll>> times(n+1);
    vector<ll> all;
    for(auto i:mp){
        times[i.sc].push_back(i.fs);
    }
    //for(auto it:st)cout<<it.fs<<' '<<it.sc<<'.';cout<<'\n';
    ll ans = 0LL;
    //int ttt = 0;
    sort(bad.begin(),bad.end());
    for(ll i = 1;i<=n;i++){
        for(ll j = i;j<=n;j++){
            for(ll p1 = times[i].size()-1;p1>=0;p1--){
                for(ll p2 = times[j].size()-1;p2>=0;p2--){
                    if(times[i][p1] != times[j][p2]&&binary_search(bad.begin(),bad.end(),make_pair(times[i][p1],times[j][p2])) == 0){
                        ans = max(ans,(i+j)*(times[i][p1]+times[j][p2]));
                        break;
                    }
                }
                p1--;
            }
        }
    }
    //cout<<ttt<<' ';
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(ll i = 0;i<t;i++)solve();
}
