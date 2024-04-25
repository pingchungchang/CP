#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n+1,vector<int>(m+1,0));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			char c;
			cin>>c;
			v[i][j] = c-'0';
		}
	}
	vector<vector<int>> ans;
	for(int i = n;i>=2;i--){
		for(int j = m;j>=2;j--){
			if(v[i][j] == 1){
				ans.push_back({i-1,j,i,j});
			}
		}
	}
	for(int i = n;i>=2;i--){
		if(v[i][1] == 1)ans.push_back({i-1,1,i,1});
	}
	for(int i = m;i>=2;i--){
		if(v[1][i] == 1)ans.push_back({1,i-1,1,i});
	}
	if(v[1][1] == 0){
		cout<<ans.size()<<'\n';
		for(auto i:ans){
			for(auto j:i)cout<<j<<' ';
			cout<<'\n';
		}
	}
	else cout<<-1<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

