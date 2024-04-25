#include <bits/stdc++.h>
using namespace std;

const int mxn = 101;
void solve(){
    int n,s;
    cin>>n>>s;
    int cnt[mxn] = {};
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        cnt[k]++;
    }
    int ans = 0;
    for(auto &i:cnt){
        ans += min(i,s);
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