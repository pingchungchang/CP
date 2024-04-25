#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
void solve(){
    int n;
    cin>>n;
    ll sum = 0;
    vector<pair<ll,ll>> v(n);
    for(ll i = 0;i<n;i++){
        cin>>v[i].fs;
        sum += v[i].fs;
    }
    for(ll i = 0;i<n;i++){
        cin>>v[i].sc;
        sum += v[i].sc;
    }
    vector<vector<ll>> dp(2,vector<ll>(sum/2+1,0LL));
    ll now = 1,pre = 0;
    dp[now][0] = 1;
    for(ll i = 0;i<n;i++){
        swap(now,pre);
        dp[now] = vector<ll>(sum/2+1,0LL);
        for(ll j = v[i].fs;j<=sum/2;j++){
            if(dp[pre][j-v[i].fs] != 0){
                dp[now][j] = j;
            }
        }
        for(ll j = v[i].sc;j<=sum/2;j++){
            if(dp[pre][j-v[i].sc] != 0){
                dp[now][j] = j;
            }
        }
    }
    ll s1 = 0,s2 = 0;
    for(ll i = sum/2;i>=0;i--){
        if(dp[now][i] != 0){
            s1 = max(s1,dp[now][i]);
            //cout<<i<<' ';
        }
    }
    //cout<<'\n';
    s2 = sum-s1;
    //cout<<s1<<' '<<s2<<'\n';
    ll ans = 0;
    for(ll i = 0;i<n;i++)ans += (n-2)*(v[i].fs*v[i].fs+v[i].sc*v[i].sc);
    ans += s2*s2+s1*s1;
    cout<<ans<<'\n';
    return;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int i = 0;i<t;i++)solve();
}

/*
1
2
9 8
72 83
*/
