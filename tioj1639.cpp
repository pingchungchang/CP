#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mxn = 4040;

int tr[mxn][mxn];
ll dp[mxn][mxn];
ll arr[mxn];
ll pref[mxn];
ll n;

ll sum(ll a,ll b){
    return pref[b]-pref[a-1];
}

/*
dp[i][j] = dp[i][k]*sum(i,k]/sum(i,j)+dp[k+1][j]*sum(k+1,j)/sum(i,j)+1
dp[i][j] = dp[i][k] + dp[k+1][j] +sum(i,j)
*/

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(auto &i:dp)for(auto &j:i)j = 1e18;
    cin>>n;
    for(int i = 1;i<=n;i++){
        dp[i][i] = 0;
        cin>>arr[i];
        pref[i] = pref[i-1]+arr[i];
    }
    for(int i = 1;i<=n;i++){
        dp[i][i] = 0;
        tr[i][i] = i;
    }
    for(int i = 2;i<=n;i++){
        for(int j = 0;j+i<=n;j++){
            int r = j+1,c = i+j;
            // cout<<r<<' '<<c<<endl;
            for(int k = tr[r][c-1];k<=tr[r+1][c];k++){
                if(k == c)continue;
                // cout<<r<<' '<<c<<' '<<k<<endl;
                if(dp[r][c]>dp[r][k]+dp[k+1][c]+sum(r,c)){
                    tr[r][c] = k;
                    dp[r][c] = dp[r][k]+dp[k+1][c]+sum(r,c);
                }
            }
        }
    }
    cout<<dp[1][n];
}
