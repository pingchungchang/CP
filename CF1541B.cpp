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
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i = 1;i<=n;i++)cin>>v[i];
	vector<int> vals(n*2+1,0);
	ll ans =0;
	for(int i = 1;i<=n;i++){
		for(ll j = 1;j*v[i]<=n*2;j++){
			if(vals[j] != 0&&i+vals[j] == j*v[i])ans++;
		}
		vals[v[i]] = i;
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

