#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pii pair<int,int>
vector<int> times(1001,INT_MAX);
void solve(){
	int n,k;
	cin>>n>>k;
	vector<pii> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].f;
		v[i].f = times[v[i].f];
	}
	for(int i = 0;i<n;i++)cin>>v[i].s;
	vector<int> dp(k+1,0);
	for(int i = 0;i<n;i++){
		for(int j = k;j>=v[i].f;j--){
			dp[j] = max(dp[j],dp[j-v[i].f]+v[i].s);
		}
	}
	cout<<dp[k]<<'\n';
	return;
	
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	times[1] = 0;
	for(int i = 1;i<=1000;i++){
		for(int j = i;j>=1;j--){
			if(i+i/j>1000)break;
			times[i+i/j] = min(times[i+i/j],times[i]+1);
		}
	}
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
