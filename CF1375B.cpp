#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m,0));
	auto vv = v;
	for(auto &i:v)for(auto &j:i)cin>>j;
	for(auto &i:vv)for(auto &j:i)j = 4;
	for(int i = 0;i<n;i++){
		vv[i][0] = vv[i][m-1] = 3;
	}
	for(int i = 0;i<m;i++){
		vv[0][i] = vv[n-1][i] = 3;
	}
	vv[0][0] = vv[n-1][0] = vv[0][m-1] = vv[n-1][m-1] = 2;
	for(int i = 0;i<n;i++){
		for(int j= 0;j<m;j++){
			if(v[i][j]>vv[i][j]){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	for(auto &i:vv){
		for(auto &j:i)cout<<j<<' ';cout<<'\n';
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
