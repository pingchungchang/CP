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
	vector<ll> s(n+1,0LL);
	vector<ll> f(n+1,0LL);
	for(ll i = 1;i<=n;i++)cin>>s[i];
	for(int i= 1;i<=n;i++)cin>>f[i];
	vector<int> ans(n+1,0);
	for(int i = 1;i<=n;i++){
		ans[i] = f[i]-max(s[i],f[i-1]);
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

