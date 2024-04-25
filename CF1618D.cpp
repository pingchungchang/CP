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
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	int p1 = n-1,p2 = n-m-1;
	ll ans= 0;
	for(int i = 0;i<m;i++){
		ans += v[p2]/v[p1];
		p1--;
		p2--;
	}
	for(int i = 0;i<n-m*2;i++)ans += v[i];
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

