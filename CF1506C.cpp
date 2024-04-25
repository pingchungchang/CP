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

void solve(){
	string a,b;
	cin>>a>>b;
	int dp[a.size()+1][b.size()+1] = {};
	for(int i = 1;i<=a.size();i++){
		for(int j = 1;j<=b.size();j++){
			if(a[i-1] == b[j-1])dp[i][j] = dp[i-1][j-1]+1;
		}
	}
	int big = 0;
	for(auto &i:dp)for(auto &j:i)big = max(j,big);
	cout<<a.size()+b.size()-big*2<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

