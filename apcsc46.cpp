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

void solve(){
	int n,l;
	cin>>l>>n;
	int dp[l+1] = {};
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		for(int i = l;i>=k;i--)dp[i] = max(dp[i],dp[i-k]+k);
	}
	if(dp[l] == l)cout<<"TAK\n";
	else cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

