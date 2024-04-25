#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn = 1e5+10;
const ll inf = 4e18;
ll dp[mxn][1<<7];
ll dp2[2][1<<7];
int n,p,m;

struct node{
	int play[7],aud,id;
	node(){}
	bool operator<(node &b){
		return aud<b.aud;
	}
};

node arr[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>p>>m;
	for(int i = 0;i<n;i++){
		cin>>arr[i].aud;
		arr[i].id = i;
	}
	for(int i = 0;i<n;i++){
		for(int j =0;j<p;j++)cin>>arr[i].play[j];
	}
	sort(arr,arr+n);
	reverse(arr,arr+n);
	//for(int i = 0;i<n;i++)cout<<arr[i].id<<' ';cout<<endl;
	fill(dp[0],dp[0]+(1<<p),-inf);
	for(int i = 0;i<p;i++)dp[0][1<<i] = arr[0].play[i];
	dp[0][0] = arr[0].aud;
	for(int i = 1;i<p+m;i++){
		fill(dp[i],dp[i]+(1<<p),-inf);
		for(int j = 0;j<(1<<p);j++){
			dp[i][j] = dp[i-1][j]+arr[i].aud;
			for(int k = 0;k<p;k++){
				if((1<<k)&j)dp[i][j] = max(dp[i][j],dp[i-1][j^(1<<k)]+arr[i].play[k]);
			}
		}
	}

	/*
	for(int i = 0;i<p+m;i++){
		for(int j = 0;j<(1<<p);j++){
			cout<<i<<" "<<j<<":"<<dp[i][j]<<endl;
		}
	}
   */

	bool roll = 0;
	fill(dp2[roll],dp2[roll]+(1<<p),-inf);
	dp2[roll][0] = 0;
	ll ans = dp[p+m-1][(1<<p)-1];
	for(int i = n-1;i>=0;i--){
		roll ^= 1;
		for(int j = 0;j<(1<<p);j++){
			dp2[roll][j] = dp2[roll^1][j];
			for(int k = 0;k<p;k++){
				if((1<<k)&j)dp2[roll][j] = max(dp2[roll][j],dp2[roll^1][j^(1<<k)]+arr[i].play[k]);
			}
			int rest = (1<<p)-1;
			rest ^= j;
			int C = __builtin_popcount(rest);
			if(m+C-1<i)ans = max(ans,dp2[roll][j]+dp[m+C-1][rest]);
			//cout<<"dp2 "<<i<<" "<<j<<":"<<dp2[roll][j]<<','<<m+C-1<<' '<<rest<<endl;
		}
	}
	cout<<ans;
}
