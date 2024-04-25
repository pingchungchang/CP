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
	vector<int> a(n+1,0),b(n+1,0),c(n+1,0),ra(n+1,0),rb(n+1,0);
	for(int i = 1;i<=n;i++)cin>>a[i];
	for(int i = 1;i<=n;i++)cin>>b[i];
	for(int i = 1;i<=n;i++)cin>>c[i];
	for(int i = 1;i<=n;i++)ra[a[i]] = i;
	for(int i = 1;i<=n;i++)rb[b[i]] = i;
	bool used[n+1] = {};
	ll ans = 1LL;
	for(int i  =1;i<=n;i++){
		if(used[a[i]])continue;
		if(a[i] == b[i]){
			used[a[i]] = true;
			continue;
		}
		int now = i;
		int flag  = true;
		while(used[a[now]] == false){
			if(c[now] != 0)flag = false;
			used[a[now]] = true;
			now = ra[b[now]];
		}
		if(flag)ans = (ans+ans>=mod?ans+ans-mod:ans+ans);
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

