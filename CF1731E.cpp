#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#define ll long long
#define int ll
const int mxn = 1e6+10;
int dp[mxn];
int lpf[mxn];
void solve(){
    ll n,m;
    cin>>n>>m;
    ll arr[n+1];
    ll cnt[n+1];
    fill(cnt,cnt+n+1,0LL);
    fill(arr,arr+n+1,0LL);
    for(int i = 2;i<=n;i++){
        int c = 1;
        cnt[i] = 0;
        // if(i*i<=n)arr[i*i]++;
        cnt[i] = dp[n/i];
    }
    ll ans = 0;
    ll total = m;
    ll sum = 0;
    for(int i = n;i>=2;i--){
        if((cnt[i]/(i-1))*(i-1)>=total){
            ans += (total/(i-1))*i;
            total %= i-1;
        }
        else{
            total -= (cnt[i]/(i-1))*(i-1);
            ans += (cnt[i]/(i-1))*i;
        }
        sum += (cnt[i]/(i-1))*(i-1);
    }
    if(sum<m)cout<<"-1\n";
    else cout<<ans<<'\n';
    // for(int i = 1;i<=n;i++)cout<<cnt[i]<<' ';cout<<'\n';

    fill(cnt,cnt+n+1,0LL);
    // for(int i= 2;i<=n;i++)for(int j = i+1;j<=n;j++)cnt[__gcd(i,j)]++;
    // for(int i = 1;i<=n;i++)cout<<cnt[i]<<' ';cout<<'\n';
    return;
}
main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 2;i<mxn;i++){
        if(!lpf[i]){
            for(int j = i;j<mxn;j+=i){
                lpf[j] = i;
            }
        }
    }
    for(int i = 2;i<mxn;i++){
        ll tmp = i;
        vector<int> facs;
        while(tmp!= 1){
            facs.push_back(lpf[tmp]);
            tmp/=lpf[tmp];
        }
        sort(facs.begin(),facs.end());
        facs.erase(unique(facs.begin(),facs.end()),facs.end());
        tmp = i;
        // if(i<=20)cout<<i<<":";
        for(auto &j:facs){
            // if(i<=20)cout<<j<<',';
            tmp = tmp*(j-1)/j;
        }
        // if(i<=20)
        // cout<<endl;
        dp[i] = tmp;
    }
    // for(int i = 1;i<=20;i++)cout<<dp[i]<<' ';cout<<endl;
    for(int i = 1;i<mxn;i++)dp[i] += dp[i-1];
    int t;
    cin>>t;
    while(t--)solve();
}