#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mxn = 1010;
const ll mod  =998244353;
ll dp[2][mxn];

ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
int main(){
    ll arr[mxn];
    short noww = 0,pre = 1;
    dp[noww][0] = 1;
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i = 0;i<k;i++){
        swap(noww,pre);
        memset(dp[noww],0LL,sizeof(dp[noww]));
        for(int j= 0;j<n;j++){
            for(int l = 1;l<=m;l++){
                if(j+l>n)dp[noww][n-(j+l-n)]+= dp[pre][j];
                else dp[noww][j+l] += dp[pre][j];
            }
        }
        for(auto &j:dp[noww])j %= mod;
        arr[i] = dp[noww][n];
    }
    ll ans = 0;
    ll inv = pw(m,mod-2);
    ll now = inv;
    //for(int i = 0;i<k;i++)cout<<arr[i]<<' ';return 0;
    for(int i = 0;i<k;i++){
        ans += now*arr[i]%mod;
        now = now*inv%mod;
        if(ans>=mod)ans -= mod;
    }
    cout<<ans;
}
//dp[i][s] = min(dp[i-1][s-arr[i]][0],dp[i-1][s-arr[i]][1]),min(dp[i-1][s][0],dp[i-1][s][1]+1)
