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
	ll n;
	cin>>n;
	ll total = 0;
	vector<ll> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
		total += v[i];
	}
	v.push_back(v[0]);
	vector<ll> ans(n,-1);
	
	if(total%(n*(n+1)/2) != 0){
		cout<<"NO\n";
		return;
	}
	total /= (n*(n+1)/2);
	for(int i = 1;i<n;++i){
		if((v[i]+total-v[i+1])%n != 0){
			cout<<"NO\n";
			return;
		}
		ans[i] = (v[i-1]+total-v[i])/n;
	}
	if((v[n-1]+total-v[0])%n != 0){
		cout<<"NO\n";
		return;
	}
	ans[0] = (v[n-1]+total-v[0])/n;
	for(auto &i:ans)if(i<=0){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
//	for(int i = n-1;i>=0;i--)cout<<ans[i]<<' ';cout<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

