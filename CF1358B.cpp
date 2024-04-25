#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	vector<ll> v(n+1,0);
	for(ll i = 1;i<=n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	ll ans = 1;
	for(ll i = 1;i<=n;i++){
		if(i>=v[i]){
			ans = i+1;
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

