#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long

const ll mod = 1e9+7;
const ll mxn = 5050;
ll fac[mxn];

ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
ll inv(ll k){
    return pw(k,mod-2);
}
ll C(ll a,ll b){
    return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}
ll mad(ll a,ll b){
    a += b;
    if(a>=mod)a -= mod;
    return a;
}
ll dp[mxn],arr[mxn],dp2[mxn];

void solve(){
    int n,k;
    cin>>n>>k;
    fill(dp,dp+n+1,0LL);
    fill(arr,arr+n+1,0LL);
    fill(dp2,dp2+n+1,0LL);
    for(int i = 1;i<=n;i++)cin>>arr[i];
    for(int i = 1;i<=n;i++){
        ll cnt = 0;
        cnt++;
        for(int j = i-1;j>=0;j--){
            if(cnt>=k)dp[i] = max(dp[i],dp[j]+k);
            if(arr[j] == arr[i])cnt++;
        }
    }
    ll ans = 0;
    for(int i = 1;i<=n;i++)ans = max(ans,dp[i]);
    ll len = ans;ans = 0;
    dp2[0] = 1;
    for(int i = 1;i<=n;i++){
        ll cnt = 0;
        cnt++;
        for(int j = i-1;j>=0;j--){
            if(cnt>=k&&dp[j] == dp[i]-k){dp2[i] = mad(dp2[i],dp2[j]*C(cnt-1,k-1)%mod);/*,cout<<i<<' '<<j<<' '<<cnt<<' '<<k<<endl;*/}
            if(arr[j] == arr[i])cnt++;
        }
    }
    for(int i = 0;i<=n;i++){
        if(dp[i] == len)ans = mad(ans,dp2[i]);
    }
    // for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';cout<<'\n';
    // for(int i = 1;i<=n;i++)cout<<dp2[i]<<' ';cout<<'\n';
    cout<<ans<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    fac[0] = fac[1] = 1;
    for(int i  =2;i<mxn;i++)fac[i] = fac[i-1]*i%mod;
    cin>>t;
    while(t--)solve();
}