#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 4e5+10;
const int C = 18;
int dp[C][mxn];
int n,q;
pii arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	memset(dp,-1,sizeof(dp));
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs>>arr[i].sc;
	}
	sort(arr,arr+n);
	int pt = n-1;
	for(int i = mxn-2;i>=0;i--){
		if(dp[0][i+1] != -1)dp[0][i] = dp[0][i+1];
		while(pt>=0&&arr[pt].fs == i){
			if(dp[0][i] == -1)dp[0][i] = arr[pt].sc;
			else dp[0][i] = min(dp[0][i],arr[pt].sc);
			pt--;
		}
		for(int j = 1;j<C;j++){
			if(dp[j-1][i] != -1&&dp[j-1][dp[j-1][i]] != -1)dp[j][i] = dp[j-1][dp[j-1][i]];
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		int ans = 0;
		for(int i = C-1;i>=0;i--){
			if(dp[i][s] != -1&&dp[i][s]<=e){
				ans += 1<<i;
				s = dp[i][s];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
