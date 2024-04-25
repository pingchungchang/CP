#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define int ll

const ll mxn = 1e5;
int dp[mxn+10];
int rest[mxn+10];
bitset<mxn+10> done;


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	fill(dp,dp+mxn+10,mxn+10);
	ll n,m;
	cin>>n>>m;
	tuple<ll,ll,ll> arr[n];
	for(auto &i:arr){
		cin>>get<0>(i)>>get<1>(i)>>get<2>(i);
	}
	dp[0] = 0;
	for(int i = 0;i<n;i++){
		memset(rest,-1,sizeof(rest));
		ll y = get<2>(arr[i]),val = (get<1>(arr[i])+mxn-1)/mxn;
		if(get<0>(arr[i]) == 1){
			val = (get<1>(arr[i])+mxn-1)/mxn;
			for(int j = 0;j<=mxn;j++){
				if(dp[j]<i+1)rest[j] = y;
				if(j+val<=m){
					rest[j+val] = max(rest[j+val],rest[j]-1);
				}
				if(rest[j]>=0)dp[j] = min(dp[j],i+1);
			}
		}
		else{
			val = get<1>(arr[i]);
			for(int j = 0;j<=m;j++){
				if(dp[j]<i+1)rest[j] = y;
				auto nxt = (j*val+mxn-1)/mxn;
				if(nxt<=m)rest[nxt] = max(rest[nxt],rest[j]-1);
				if(rest[j]>=0)dp[j] = min(dp[j],i+1);
			}
		}
		//for(int j = 0;j<=m;j++)cout<<(dp[j] > mxn?-1:dp[j])<<' ';cout<<'\n';
	}
	for(int i = 1;i<=m;i++)if(dp[i]>mxn)dp[i] = -1;
	for(int i = 1;i<=m;i++)cout<<dp[i]<<' ';
	return 0;
}
