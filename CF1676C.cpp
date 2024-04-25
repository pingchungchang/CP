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
	vector<string> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	ll ans = INT_MAX;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			ll tmp = 0;
			for(int k = 0;k<m;k++){
				ll diff = (v[i][k]>v[j][k]?v[i][k]-v[j][k]:v[j][k]-v[i][k]);
				tmp += diff;
			}
			ans = min(ans,tmp);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

