#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
ll dp[mxn];

void solve(){
	int n;
	cin>>n;
	cout<<dp[n]<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 1;i<mxn;i++){
		dp[i] = dp[i-1];
		int t = i;
		while(t){
			dp[i] += t%10;
			t/=10;
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
