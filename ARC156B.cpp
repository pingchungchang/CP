#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxn = 4e5+10;
int pref[mxn];
int arr[mxn];
ll fac[mxn*2];
const ll mod= 998244353;
ll pw(ll a,ll b){
    ll re = 1;
    while(b){
        if(b&1)re = re*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return re;
}
ll inv(ll tmp){
    return pw(tmp,mod-2);
}
ll C(ll a,ll b){
    return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr[tmp]++;
        pref[tmp] = 1;
    }
    ll ans = 0;
    fac[0] = fac[1] = 1;
    for(int i = 2;i<mxn*2;i++)fac[i] = fac[i-1]*i%mod;
    for(int i = 1;i<mxn;i++)pref[i] += pref[i-1];
    for(int i = 0;i<mxn;i++){
        ll rest = k-(i+1-pref[i]);
        if(arr[i])rest--;
        if(rest<0)continue;
        // cout<<i<<endl;
        ans += C(rest+i,rest);
        ans %= mod;
    }
    // cout<<"HI"<<endl;return 0;
    cout<<ans;
}