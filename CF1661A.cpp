#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i = 0;i<n;i++)cin>>v[i].fs;
    for(int i = 0;i<n;i++){
        cin>>v[i].sc;
        v[i] = make_pair(max(v[i].fs,v[i].sc),min(v[i].fs,v[i].sc));
    }
    ll ans = 0;
    for(int i = 1;i<n;i++){
        ans += abs(v[i].fs-v[i-1].fs);
        ans += abs(v[i].sc-v[i-1].sc);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}
