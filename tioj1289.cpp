#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first
#define sc second
int n;
map<ll,int> mp;
const int mxn = 2022;
ll arr[mxn];
void solve(){
    ll ans = 0;
    mp.clear();
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]*arr[i]]++;
    }
    for(auto it = mp.begin();it != mp.end();it++){
        for(auto it2 = it;it2 != mp.end();it2++){
            //cout<<it->fs<<' '<<it2->fs<<' ';
            if(it == it2||it->fs <= 0||it->sc<=0)continue;
            ans += it->sc*it2->sc*(mp.find(it->fs+it2->fs) != mp.end()?mp[it->fs+it2->fs]:0LL);
        }
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        if(!n)return 0;
        solve();
    }
}
