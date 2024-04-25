#include <bits/stdc++.h>
using namespace std;

#define int ll
#define ll long long
const int mxn = 2e5+10;
int arr[mxn];
ll ans = 0;
vector<ll> v[mxn];
main(){
    ll n;
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>arr[i];
    ll ans = 0;
    for(int i = 1;i<=n;i++){
        ans += (n-i+1)*((i+1)/2);
        // cout<<ans<<endl;
        v[arr[i]].push_back(i);
    }
    // cout<<ans<<endl<<endl;
    for(auto &tmp:v){
        if(tmp.empty())continue;
        // for(auto &i:tmp)cout<<i<<" ";cout<<":";
        ll pref[tmp.size()];
        pref[0] = tmp[0];
        for(int i = 1;i<tmp.size();i++){
            pref[i] = tmp[i];
            pref[i] += pref[i-1];
        }
        int p = 0;
        for(int i = tmp.size()-1;i>=0;i--){
            p = min(p,i);
            while(p<=i&&tmp[p]<=n+1-tmp[i])p++;
            p--;
            if(p<0){
                p = 0;
                ans = ans-(i+1)*(n+1-tmp[i]);
                // cout<<i<<' '<<-1<<' '<<(i+1)*(n+1-tmp[i])<<',';
                continue;
            }
            ans = ans-pref[p]-(i-p)*(n+1-tmp[i]);
            // cout<<i<<' '<<p<<' '<<pref[p]+(i-p)*(n+1-tmp[i])<<',';
        }
        // cout<<endl;
    }
    cout<<ans;
}
/*
for i,j if a[i] != a[j] ans += min(i+1,n-j)
for i,j if a[i] == a[j] ans -= min(i+1,n-j)
*/