#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	string s;
	cin>>s;
	int n = s.size();
	vector<ll> dp(n,-1);
	for(int i = 2;i<n;i++){
		dp[i] = dp[i-1];
		int p = dp[i-1];
		for(int j = p+1;j<i;j++){
			if(((j+i)&1) == 0&&(s[j] == s[i]&&s[i] == s[(i+j)>>1])){
				dp[i] = j;
			}
		}
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ans += (dp[i]+1);
	}
	cout<<ans;
}

