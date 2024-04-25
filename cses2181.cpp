#include <bits/stdc++.h>
using  namespace std;
#define ll long long
const ll mod = 1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    ll all = 1<<n;
    ll dp[2][(ll)(1<<11)];
    int a = 0,b = 1;
    memset(dp,0,sizeof(dp));
    dp[0][all-1] = 1;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            swap(a,b);
            memset(dp[a],0,sizeof(dp[a]));
            for(ll k = 0;k<all;k++){
                ll l,u;
                if(j == 0)l = 1;
                else l = (k&(1<<(j-1)));
                u = k&(1<<j);
                if(u == 0){
                    dp[a][k^(1<<j)]+= dp[b][k];
                    dp[a][k^(1<<j)] %= mod;
                }
                else{
                    if(l != 0){
                        dp[a][k^(1<<(j))]+= dp[b][k];
                        dp[a][k^(1<<j)]%= mod;
                    }
                    else{
                        dp[a][k^(1<<j)]+= dp[b][k];
                        dp[a][k^(1<<(j-1))]+= dp[b][k];
                        dp[a][k^(1<<j)]%=mod;
                        dp[a][k^(1<<(j-1))]%=mod;
                    }
                }
            }
//          for(int k = 0;k<all;k++){
//            	cout<<dp[b][k]<<' ';
//			}
//			return 0;
        }
    }
    cout<<dp[a][all-1];
}
