#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> v(n,vector<int>(n));
	for(auto &i:v){
		for(auto &j:i)cin>>j;
	}
	int ans = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(v[i][j] != v[n-1-i][n-1-j])ans++;
		}
	}
	assert(ans%2 == 0);
	ans>>=1;
	if(ans>k)cout<<"NO\n";
	else if(n&1)cout<<"YES\n";
	else if((k-ans)%2 == 0)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
