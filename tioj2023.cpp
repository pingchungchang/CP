#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn =22;
ll dp[1<<mxn];
string s;
int n,m;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	while(m--){
		string s;
		int b = 0,val = 0;
		cin>>s>>val;
		for(int j = 0;j<n;j++){
			b ^= (1<<j)*(s[j] == '1');
		}
		dp[b] += val;
	}
	for(int i = 0;i<mxn;i++){
		for(int j = 0;j<(1<<mxn);j++){
			if(j&(1<<i))dp[j] += dp[j^(1<<i)];
		}
	}
	sort(dp+1,dp+(1<<n));
	ll ans =0;
	for(int i = 1;i<(1<<n);i++){
		ans += dp[i]*(i);
	}
	cout<<ans;
}
