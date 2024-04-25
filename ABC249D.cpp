#include <bits/stdc++.h>
using namespace std;


#define ll long long
int mxn = 1e5*2+10;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<ll> times(mxn,0);
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
        times[v[i]]++;
    }
    vector<ll> dp(mxn,-1);
    ll ans = 0;
    for(int i = 0;i<n;i++){
        if(dp[v[i]] != -1){
            continue;
        }
        dp[v[i]] = 0;
        int k = sqrt(v[i]);
        for(int j= 1;j<=k;j++){
            if(v[i]%j != 0)continue;
            int l = v[i]/j;
            dp[v[i]] += times[v[i]]*times[l]*times[j];
            if(l != j)dp[v[i]] += times[v[i]]*times[l]*times[j];
        }
        ans += dp[v[i]];
    }
    /*vector<ll> dp2(mxn,0);
    for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)for(int k = 0;k<n;k++)if(v[i] == v[j]*v[k]){
        dp2[v[i]]++;
    }
    for(auto i:v)cout<<dp[i]<<' '<<dp2[i]<<endl;cout<<endl;*/
    cout<<ans;//<<' '<<total2;
}
