#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define ld long double


void solve(){
	int n,m;
	cin>>n>>m;
	int arr[n+1];
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int p = n;
	for(;p>0&&arr[p] == p;p--);
	pair<int,ld> v[m];
	for(auto &i:v)cin>>i.fs>>i.sc;
	ld ans = 0;
	ld pre = 1.0;
	if(p == 0){
		cout<<1.0000000<<'\n';
		return;
	}
	for(auto &i:v)if(i.fs>=p)ans += pre*i.sc,pre*=(1-i.sc);
	cout<<fixed<<setprecision(10)<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
