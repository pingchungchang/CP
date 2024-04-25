#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mod = 998244353;
const int mxn = 3030;
pii dp[2][mxn];

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}
inline int mub(int a,int b){
	return mad(a,mod-b);
}
int dir(int ls,int self){
	int rs = 0-self-ls;
	ls -= rs;
	ls *= self;
	return ls>0?1:-1;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	bool roll = false;
	int n;
	string s;
	cin>>n>>s;
	s = "#"+s;
	dp[roll][0].sc = 1;
	for(int i = 1;i<=n*2;i++){
		roll ^= 1;
		for(auto &j:dp[roll])j = {0,0};
		if(s[i] != '+'){//=-or?
			for(int pre = 0;pre<=n;pre++){
				int ls = pre-(i-1-pre);
				int d = dir(ls,-1);
				dp[roll][pre].sc = mad(dp[roll][pre].sc,dp[roll^1][pre].sc);
				dp[roll][pre].fs = mad(dp[roll][pre].fs,dp[roll^1][pre].fs);
				if(d<0)dp[roll][pre].fs = mad(dp[roll][pre].fs,1ll*dp[roll^1][pre].sc*i%mod);
				else dp[roll][pre].fs = mub(dp[roll][pre].fs,1ll*dp[roll^1][pre].sc*i%mod);
			}
		}
		if(s[i] != '-'){//=+or?
			for(int pre = 1;pre<=n;pre++){
				int ls = pre-1-(i-1-(pre-1));
				int d = dir(ls,1);
				dp[roll][pre].sc = mad(dp[roll][pre].sc,dp[roll^1][pre-1].sc);
				dp[roll][pre].fs = mad(dp[roll][pre].fs,dp[roll^1][pre-1].fs);
				if(d<0)dp[roll][pre].fs = mad(dp[roll][pre].fs,1ll*dp[roll^1][pre-1].sc*i%mod);
				else dp[roll][pre].fs = mub(dp[roll][pre].fs,1ll*dp[roll^1][pre-1].sc*i%mod);
			}
		}
	}
	cout<<dp[roll][n].fs;
}
