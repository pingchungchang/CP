#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1010;
int dp[mxn][mxn];
vector<int> fac[2];

void solve(){
	fac[0].clear();
	fac[1].clear();
	memset(dp,0,sizeof(dp));
	int a,b;
	cin>>a>>b;
	for(int i = 1;i*i<=a;i++){
		if(a%i == 0){
			fac[0].push_back(i);
			if(i*i != a)fac[0].push_back(a/i);
		}
	}
	for(int i = 1;i*i<=b;i++){
		if(b%i == 0){
			fac[1].push_back(i);
			if(i*i != b)fac[1].push_back(b/i);
		}
	}
	sort(fac[0].begin(),fac[0].end());
	sort(fac[1].begin(),fac[1].end());
	assert(fac[0].size()<mxn&&fac[1].size()<mxn);

	dp[0][0] = 0;
	for(int i = 0;i<fac[0].size();i++){
		for(int j = 0;j<fac[1].size();j++){
			if(dp[i][j] == 0){
				for(int k = i+1;k<fac[0].size();k++){
					if(fac[0][k]%fac[0][i] == 0&&fac[0][k]>=fac[1][j])dp[k][j] = 1;
				}
				for(int k = j+1;k<fac[1].size();k++){
					if(fac[1][k]%fac[1][j] == 0&&fac[0][i]<=fac[1][k])dp[i][k] = 1;
				}
			}
		}
	}

	if(dp[fac[0].size()-1][fac[1].size()-1] == 0)cout<<"Zisk\n";
	else cout<<"Danb\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
