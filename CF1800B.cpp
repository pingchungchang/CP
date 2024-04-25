#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char,int> mp;
    for(auto &i:s){
        mp[i]++;
    }
    int ans = 0;
    for(int i = 'A';i<='Z';i++){
        ans += min(mp[i],mp[i-'A'+'a']);
        int d = max(mp[i],mp[i-'A'+'a'])-min(mp[i],mp[i-'A'+'a']);
        ans += min(d/2,k);
        k -= min(d/2,k);
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