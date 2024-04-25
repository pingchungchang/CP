#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

ll dp[20][20];

ll C(int a,int b){
	if(dp[a][b] != -1)return dp[a][b];
	if(a<b)return dp[a][b] = 0ll;
	return dp[a][b] = C(a-1,b)+C(a-1,b-1);
}


void solve(){
	string s;
	cin>>s;
	ll ans = 1;
	for(auto &i:s){
		ll tmp = i-'0';
		ans = ans*(tmp+1)*(tmp+2)/2;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp,-1,sizeof(dp));
	for(int i = 1;i<15;i++)for(int j = 1;j<15;j++)C(i,j);
	int t;cin>>t;
	while(t--)solve();
}
