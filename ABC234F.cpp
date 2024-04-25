#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const ll mod = 998244353;
const ll mxn = 5005;
ll cc[mxn][mxn];
ll dp[2][mxn];

ll C(ll a,ll b){
	if(b>a||a<0||b<0)return 0;
	if(b == 0){
		cc[a][b] = 1;
		return 1;
	}
	if(cc[a][b] == 0)cc[a][b] = C(a-1,b)+C(a-1,b-1);
	if(cc[a][b]>=mod)cc[a][b] -= mod;
	return cc[a][b];
}
int main(){
	io
	string s;
	cin>>s;
	short now = 1;
	C(mxn-1,mxn-1);
	ll cnt[26] = {};
	for(auto &i:s)cnt[i-'a']++;
	dp[now][0] = 1;
	for(int i = 0;i<26;i++){
		now ^= 1;
		for(int j = 0;j<mxn;j++)dp[now][j] = 0;
		for(int j = mxn-1-cnt[i];j>=0;j--){
			for(int k = 0;k<=cnt[i];k++){
				dp[now][j+k] += dp[now^1][j]*C(j+k,k)%mod;
				if(dp[now][j+k]>=mod)dp[now][j+k] -= mod;
			}
		}
//		cout<<(char)('a'+i)<<' ';for(int ii = 0;ii<4;ii++)cout<<dp[now][ii]<<' ';cout<<endl;
	}
	ll ans = 0;
	for(auto &i:dp[now])ans += i;
	ans--;
	ans %= mod;
	cout<<ans;
}

