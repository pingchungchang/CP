#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> dp(m+1,0LL);
    vector<ll> pref(m+1,0LL);
    for(ll i= 1;i<=m;i++)dp[i] = 1;
    for(ll i = 1;i<=m;i++){
        pref[i] = dp[i];
        pref[i] += pref[i-1];
        pref[i]%= mod;
    }
    for(ll i =1;i<n;i++){
        for(ll j = 1;j<=m;j++){
            dp[j] = 0;
            if(k == 0)dp[j] = pref.back();
            else{
                if(j-k>0){
                    dp[j] += pref[j-k];
                }
                if(j+k<=m){
                    dp[j] += pref.back()-pref[j+k-1]+mod;
                }
            }
            dp[j] %= mod;
        }
        for(ll j = 1;j<=m;j++){
            pref[j] = dp[j];
            pref[j] += pref[j-1];
            pref[j]%= mod;
        }
        //for(ll j = 1;j<=m;j++)cout<<dp[j]<<' ';cout<<endl;
        //for(ll j = 1;j<=m;j++)cout<<pref[j]<<' ';cout<<endl<<endl;
    }
    cout<<pref.back()%mod;
    return 0;
}
