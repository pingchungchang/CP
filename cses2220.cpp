#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll rec(string s){
	if(s.size() == 1)return 1LL*(s[0]-'0');
	vector<vector<ll>> dp(2,vector<ll>(10,0));
	int t = 0;
	int n = s.size();
	char ppp = '#';
	int d = INT_MAX;
	for(int i = 0;i<n;i++){
		if(s[i] == ppp){
			d = i;
			break;
		}
		ppp = s[i];
	}
	
	for(int i = 0;i<s[0]-'0';i++){
		dp[0][i] = 1;
	}

	t ^= 1;
	ll ans = 0;
	for(int i = 1;i<n;i++){
		pt(dp[!t]);
		for(int j = 0;j<10;j++){
			dp[t][j] = 0;
			for(int k = 0;k<10;k++){
				if(j == k)continue;
				dp[t][j] += dp[!t][k];
			}
		}
		for(int j = 0;d>=i&&j<s[i]-'0';j++){
			if(j == s[i-1]-'0')continue;
			dp[t][j]++;
		}
		t ^= 1;
	}
	pt(dp[!t]);
	t^=1;
	if(d>=n&&s.size()>=2&&s[n-1] != s[n-2])dp[t][s[n-1]-'0']++;
	else if(d>=n&&s.size()<2){
		dp[t][s[n-1]-'0']++;
	}
	
	cout<<endl;
	
	for(auto i:dp[t])ans += i;
	if(s.size()>2){
		s = s.substr(2,s.size()-2);
		for(auto &i:s)i = '9';
		ans += rec(s);
	}
	return ans;
}
int main(){
	ll aa,bb;
	cin>>aa>>bb;
	string a = to_string(aa);
	string b = to_string(bb);
	ll ans = rec(b)-rec(a);
	char pre = '#';
	bool add = true;
	for(char i:a){
		if(i == pre)add = false;
		pre = i;
	}
	if(add)ans++;
	cout<<ans;
}
