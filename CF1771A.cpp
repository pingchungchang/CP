#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second

void solve(){
    int n;
    cin>>n;
    map<int,int> mp;
    while(n--){
        int k;
        cin>>k;
        mp[k]++;
    }
    if(mp.begin()->first != mp.rbegin()->first){
        cout<<1LL*mp.begin()->sc*mp.rbegin()->sc*2<<'\n';
    }
    else cout<<1LL*(mp.begin()->sc-1)*(mp.rbegin()->sc)<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}