#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 55;
ll arr[mxn];
map<ll,ll> mp;

void solve(){
    mp.clear();
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)cin>>arr[i];
    for(int i = 0;i<n;i++){
        set<ll> st;
        for(int j = i-1;j>=0;j--){
            ll dif = arr[i]-arr[j];
            for(ll k = 1;k*k<=dif;k++){
                if(dif%k != 0)continue;
                ll a = (dif/k-k)/2;
                if(a*a<arr[j]||(a+k)*(a+k)<arr[i]||a<0||k*(2*a+k) != dif)continue;
                if(st.find(a*a-arr[j]) != st.end())continue;
                st.insert(a*a-arr[j]);
                // cout<<a<<' '<<i<<' '<<j<<' '<<a*a-arr[j]<<endl;
                if(!mp[a*a-arr[j]])mp[a*a-arr[j]] = 2;
                else mp[a*a-arr[j]]++;
            }
        }
    }
    ll ans = 1;
    for(auto &i:mp)ans = max(ans,i.second);
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}
/*
(a+k)^2-a^2 = k*(k+2a)

*/