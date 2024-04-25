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

const ll mod = 1e9+7;
void add(ll &a,ll b){
	a += b;
	if(a>=mod)a -= mod;
	return;
}
int main(){
	io
	int n;
	cin>>n;
	string s;
	cin>>s;
	int m = s.size();
	int p[m] = {};
	if(m>1&&s[0] == s[1])p[1] = 1;
	for(int i = 2;i<m;i++){
		int pt = p[i-1];
		while(pt>0&&s[pt] != s[i]){
			pt = p[pt-1];
		}
		if(pt <= 0&&s[i] != s[0])p[i] = 0;
		else p[i] = pt+1;
	}
//	for(auto &i:p)cout<<i<<' ';
//	return 0;
	ll dp[2][m+1];
	memset(dp,0LL,sizeof(dp));
	short now = 0,pre = 1;
	dp[now][0] = 25;
	dp[now][1] = 1;
	for(int i = 1;i<n;i++){
		swap(now,pre);
		memset(dp[now],0LL,sizeof(dp[now]));
		for(int j = 1;j<m;j++){
			for(int k = 0;k<26;k++){
				if(k == s[j]-'A'){
					add(dp[now][j+1],dp[pre][j]);
					continue;
				}
				int pt = p[j-1];
				while(pt>0&&s[pt]-'A' != k){
					pt = p[pt-1];
				}
				if(pt<=0&&s[0]-'A' != k)add(dp[now][0],dp[pre][j]);
				else add(dp[now][pt+1],dp[pre][j]);
			}
		}
		add(dp[now][1],dp[pre][0]);
		add(dp[now][0],dp[pre][0]*25%mod);
		add(dp[now][m],dp[pre][m]*26%mod);
//		for(int j = 0;j<=m;j++)cout<<dp[now][j]<<' ';cout<<endl;
	}
	
	
	cout<<dp[now][m];
	
}

