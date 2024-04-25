#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxK = 12,mxL = 110;
int dp[2][mxK][mxL][2];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string a,b;
	int L,K;
	cin>>L>>K;
	memset(dp,-1,sizeof(dp));
	bool roll = 0;
	dp[roll][0][0][0] = 0;
	int n = a.size(),m = b.size();
	a = "#"+a;
	b = "#"+b;
	int ans = mxK;
	for(int i = 1;i<=n;i++){
		roll ^= 1;
	}
}
