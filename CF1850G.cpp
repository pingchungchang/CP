#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	pll arr[n];
	map<ll,ll> mp[4];//x,y,x+y,x-y
	ll ans = 0;
	for(auto &i:arr){
		cin>>i.fs>>i.sc;
		ans += mp[0][i.fs]+mp[1][i.sc]+mp[2][i.fs+i.sc]+mp[3][i.fs-i.sc];
		mp[0][i.fs]++;mp[1][i.sc]++;mp[2][i.fs+i.sc]++;mp[3][i.fs-i.sc]++;
	}
	cout<<ans*2<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
