#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int inf = 1e9;
const int mxn = 1e4+10;
int dp[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int arr[n];
	int mx = 0;
	for(auto &i:arr)cin>>i,mx = max(mx,i);
	fill(dp,dp+mxn,-inf);
	dp[0] = 0;
	while(m--){
		int k;
		cin>>k;
		for(int i = mx;i>=k;i--)dp[i] = max(dp[i],dp[i-k]+1);
	}
	int big = -1,pos = -1;
	for(int i = 0;i<n;i++){
		if(dp[arr[i]]<=0)continue;
		if(big<dp[arr[i]])big = dp[arr[i]],pos = i+1;
	}
	if(big == -1)cout<<big;
	else cout<<pos<<' '<<big;
}
