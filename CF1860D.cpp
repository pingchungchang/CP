#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


string s;
const int mxn = 110;
int dp[2][mxn][mxn*mxn*2];
const int sh = mxn*mxn;
int z = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s;
	int n = s.size();
	s = "#"+s;
	for(int i = 1;i<=n;i++)if(s[i] == '0')z++;
	for(auto &i:dp)for(auto &j:i)for(auto &k:j)k = sh;
	bool roll = 0;
	dp[roll][0][sh] = 0;
	for(int i = 1;i<=n;i++){
		roll ^= 1;
		for(auto &j:dp[roll])for(auto &k:j)k = sh;
		for(int j = 0;j<=z;j++){
			ll o = i-j;
			if(o>n-z)continue;
			for(int l = sh-n*n;l<=sh+n*n;l++){//l = 01-10
				//cout<<i<<' '<<j<<' '<<l-sh<<":";
				// add 1
				if(o){
					int d = l+j;
					dp[roll][j][l] = min(dp[roll][j][l],dp[roll^1][j][d]+(s[i] != '1'));
					//cout<<i-1<<' '<<j<<' '<<d-sh<<',';
				}
				if(j){
					// add 0
					int d = l-o;
					dp[roll][j][l] = min(dp[roll][j][l],dp[roll^1][j-1][d]+(s[i] != '0'));
					//cout<<i-1<<' '<<j-1<<' '<<d-sh<<',';
					//cout<<dp[roll][j][l]<<endl;
				}
			}
		}
	}
	cout<<dp[roll][z][sh]/2;
}
