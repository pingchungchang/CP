#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 998244353;
const ll mxn = 3e5+10;

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
ll fac[mxn];
ll C(ll a,ll b){
    return fac[a]*inv(fac[b])%mod*inv(fac[a-b])%mod;
}
ll arr[mxn][3];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fac[0] = fac[1] = 1;
    for(int i = 2;i<mxn;i++){
        fac[i] = fac[i-1]*i%mod;
    }

    ll n;
    cin>>n;
    n/=3;
    ll s2 = 0;
    ll same = 0;
    for(int i  =1;i<=n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        sort(arr[i],arr[i]+3);
        if(arr[i][0] == arr[i][2])same++;
        else if(arr[i][0] == arr[i][1])s2++;
    }
    cout<<C(n,n/2)*pw(3,same)%mod*pw(2,s2)%mod;
    /*
    C(n,n/2)*2*pw(3,same);
    */
}
/*
*/