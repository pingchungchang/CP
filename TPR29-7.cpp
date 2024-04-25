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
const ll mxn = 2e4+10;
ll dp[2][mxn];
int main(){
	io
	int n;
	cin>>n;
	short now = 0;
	dp[now][0] = 1;
	ll arr[3];
	for(auto &i:arr)cin>>i;
	int q;
	cin>>q;
	while(n--){
		now ^=1;
		for(auto &i:dp[now])i = 0;
		for(int i = 0;i<mxn;i++){
			for(auto &j:arr){
				if(j>i)continue;
				dp[now][i] += dp[now^1][i-j];
			}
		}
//		for(int i = 0;i<=50;i+=10)cout<<dp[now][i]<<' ';cout<<endl;
	}
	for(int i = 1;i<mxn;i++){
		dp[now][i] += dp[now][i-1];
	}
	while(q--){
		ll a = 1,b;
		cin>>b;
		cout<<dp[now][b]-dp[now][a-1]<<'\n';
	}
}

