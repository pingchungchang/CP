#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
	int n,m;
	cin>>n>>m;
	ll ans = 0;
	vector<vector<ll>> v(n,vector<ll>(m));
	for(int i = 0;i<n;i++)for(int j = 0;j<m;j++)cin>>v[i][j];
	for(int i = 0;i<=n/2;i++){
		for(int j = 0;j<=m/2;j++){
			vector<ll> tmp = {v[i][j],v[n-1-i][j],v[n-1-i][m-1-j],v[i][m-1-j]};
			sort(tmp.begin(),tmp.end());
			ll add = tmp[3]-tmp[0]+tmp[2]-tmp[1];
			if(i == n-1-i||j == m-1-j)add/=2;
			ans += add;
			v[i][j] = 0;
			v[i][m-1-j] = 0;
			v[n-1-i][j] = 0;
			v[n-1-i][m-1-j] = 0;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

