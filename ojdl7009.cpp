#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,popcnt")
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 5e4+10;
bitset<mxn> dp[mxn];
int n,q;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 1;i<=n;i++)dp[i][i] = true;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int a,b;
			cin>>a>>b;
			dp[a] = dp[b] = (dp[a]|dp[b]);
		}
		else{
			int a;
			cin>>a;
			cout<<dp[a].count()<<'\n';
		}
	}
	return 0;
}
