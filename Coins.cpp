#include <bits/stdc++.h>
using namespace std;

#define d double
int main(){
	int n;
	cin>>n;
	vector<d> dp(n+1,0.0);
	vector<d> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	dp[0] = 1;
	for(int i = 0;i<n;i++){
		for(int j = n;j>=0;j--){
			dp[j] = dp[j]*(1-v[i]);
			if(j != 0)dp[j] += dp[j-1]*v[i];
		}
	}
	d ans = 0;
	for(int i = (n+1)/2;i<=n;i++)ans += dp[i];
	cout<<fixed<<setprecision(10)<<ans;
}
