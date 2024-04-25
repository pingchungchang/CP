#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    int m;
    cin>>n;
    cin>>m;
    vector<int> v[n+1];
    int cnt[n+1] = {};
    while(m--){
        int a,b;
        cin>>a>>b;
        v[min(a,b)].push_back(max(a,b));
    }
    int p = 1;
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        while(p<=n&&cnt[p] == 0){
            for(auto &j:v[p])cnt[j]++;
            p++;
        }
        ans += p-i;
        for(auto &j:v[i])cnt[j]--;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}