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
const ll mxn = 2020;
ll dp[mxn][mxn];
const ll mod = 1e9+7;
string arr[mxn];
ll ver[mxn];
ll hor[mxn];
ll lu[mxn];
ll add(ll a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	if(a<0)a += mod;
	return a;
}
int main(){
	io
	ll n,m;
	cin>>n>>m;
	for(auto &i:arr)i = string(mxn,'#');
	for(int i = 1;i<=n;i++)for(int j = 1;j<=m;j++)cin>>arr[i][j];
	dp[1][1] = 1;
	hor[1] = 1;
	ver[1] = 1;
	for(int i = 2;i<=m;i++){
		if(arr[1][i] == '#'){
			hor[i] = 0;
			continue;
		}
		dp[1][i] = hor[i-1];
		ver[i] = dp[1][i];
		hor[i] = add(hor[i-1],dp[1][i]);
	}
	for(int i = 2;i<=m;i++)lu[i] = dp[1][i-1]; 
	for(int i = 2;i<=n;i++){
//		for(int j = 1;j<=m;j++)cout<<lu[j]<<" ";cout<<"\n\n";
//		hor[1] = ver[1];
		hor[0] = hor[1] = 0;
		for(int j = 1;j<=m;j++){
			if(arr[i][j] == '#'){
				hor[j] = 0;
				ver[j] = 0;
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = add(add(hor[j-1],ver[j]),lu[j]);
			hor[j] = add(hor[j-1],dp[i][j]);
			ver[j] = add(ver[j],dp[i][j]);
		}
		for(int j = m-1;j>=1;j--){
			if(arr[i][j] == '#')lu[j+1] = 0;
			else lu[j+1] = add(lu[j],dp[i][j]);
		}
	}
//	for(int i= 1;i<=n;i++){
//		for(int j =1;j<=m;j++)cout<<dp[i][j]<<' ';cout<<endl;
//	}
	cout<<dp[n][m];
}

