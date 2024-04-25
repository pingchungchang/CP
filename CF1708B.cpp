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
	ll n,l,r;
	cin>>n>>l>>r;
	vector<ll> ans(n+1,0);
	for(int i = 1;i<=n;i++){
		ans[i] = r/i*i;
		if(ans[i]<l){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

