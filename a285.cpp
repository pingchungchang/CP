#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int t;
	cin>>t;
	int n;
	cin>>n;
	vector<int> dp(t+1,0);
	vector<int> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = t;j>=v[i];j--){
			dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
		}
	}
	cout<<dp[t];
}

