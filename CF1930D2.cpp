#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 1e6+10;
ll dp[mxn],n;
string s;

inline ll f(string s){
	int re = 0,r = -1;
	for(int i = 0;i<s.size();i++){
		if(s[i] == '0')continue;
		if(r<i)r = i+2,re++;
	}
	return re;
}

void solve(){
	cin>>n;
	cin>>s;
	s = "#"+s;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		dp[i] = 0;
		if(s[i] == '0')dp[i] = dp[i-1];
		else{
			if(i>=3)dp[i] = dp[i-3]+i-3;
			for(int j = 1;j<=min(i,3);j++)dp[i] += f(s.substr(i-j+1,j));
		}
		ans += dp[i];
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}

