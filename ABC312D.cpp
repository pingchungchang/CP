#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3030;
const ll mod = 998244353;

inline ll mad(ll a,ll b){
	a += b;
	return a>=mod?a-mod:a;
}
inline ll mub(ll a,ll b){
	if(!b)return a;
	else return mad(a,mod-b);
}

ll dp[mxn][mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	s = "#"+s;
	dp[0][0] = 1;
	for(int i = 1;i<s.size();i++){
		if(s[i] != ')'){
			for(int j = 1;j<mxn;j++){
				dp[i][j] = mad(dp[i][j],dp[i-1][j-1]);
			}
		}
		if(s[i] != '('){
			for(int j = 0;j<mxn-1;j++){
				dp[i][j] = mad(dp[i][j],dp[i-1][j+1]);
			}
		}
	}
	cout<<dp[s.size()-1][0];
}
