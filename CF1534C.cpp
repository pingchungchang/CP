#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

const ll mod = 1e9+7;
void solve(){
	int n;
	cin>>n;
	vector<vector<int>> v(n+1,vector<int>(2)),inv(n+1,vector<int>(2));
	for(int i = 0;i<2;i++)for(int j = 1;j<=n;j++){
		cin>>v[j][i];
		inv[v[j][i]][i] = j;
	}
//	for(int i = 1;i<=n;i++)cout<<inv[i][0]<<' ';cout<<'\n';return;
	vector<bool> goneto(n+1,0);
	ll ans = 1;
	for(int i = 1;i<=n;i++){
		int now = i;
		if(goneto[i] == 0)ans = ans*2%mod;
//		cout<<now<<' '<<goneto[now]<<",";
		while(goneto[now] == 0){
			goneto[now] = 1;
			now = inv[v[now][1]][0];
//			cout<<now<<',';
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

