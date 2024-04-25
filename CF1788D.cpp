#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn =3030;
const ll inf = 1e18;
const ll mod = 1e9+7;
pll dp[mxn][mxn][2];
//first:count,second:total
ll arr[mxn];


ll mad(ll a,ll b){
	if(b==mod)b = 0;
	a += b;
	if(a>=mod)a -= mod;
	return a;
}
ll mub(ll a,ll b){
	return mad(a,mod-b);
}

const pll operator+(pll a,pll b){
	return make_pair(mad(a.fs,b.fs),mad(a.sc,b.sc));
}
const pll operator-(pll a,pll b){
	return make_pair(mub(a.fs,b.fs),mub(a.sc,b.sc));
}

int main(){
	ll n;
	cin>>n;
	arr[0] = -inf;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll ans = 0;
	dp[1][0][1] = {1,0};
	for(int i = 1;i<=n;i++)dp[1][i][1] = {1,0};
	for(int i = 2;i<=n;i++){
		for(auto &j:dp[i])for(auto &k:j)k = {0,0};
		for(int j = 1;j<i;j++){
			ll dist = arr[i]-arr[j];
			ll lpos = arr[j]-dist;
			lpos = lower_bound(arr,arr+j+1,lpos)-arr-1;
			//cout<<i<<' '<<j<<":"<<lpos<<endl;
			dp[i][j][0] = dp[j][lpos][0]+dp[j][lpos][1];
			dp[i][j][0].sc = mad(dp[i][j][0].sc,dp[j][lpos][1].fs);
			dp[i][j][1] = dp[j][j][0]-dp[j][lpos][0]+dp[j][j][1]-dp[j][lpos][1];
			//ans = mad(mad(ans,dp[roll][j][0].sc),dp[roll][j][1].sc);
		}
		dp[i][0][1] = dp[i][0][1]+make_pair(1,0);
		for(int j = 1;j<=n;j++){
			dp[i][j][0] = dp[i][j][0]+dp[i][j-1][0];
			dp[i][j][1] = dp[i][j][1]+dp[i][j-1][1];
		}
		ans = mad(mad(ans,dp[i][n][0].sc),dp[i][n][1].sc);
		//cout<<ans<<','<<dp[i][i][0].fs<<','<<dp[i][i][1].fs<<endl;
	}
	cout<<ans;
}
/*
dp[i][j][0]:right
dp[i][j][1]:left
*/

