#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,m;
	cin>>n>>m;
	pll now = {m,m};
	int t = 0;
	pll arr[n];
	ll brr[n];
	for(int i = 0;i<n;i++){
		cin>>brr[i]>>arr[i].fs>>arr[i].sc;
	}
	bool flag = true;
	for(int i = 0;i<n;i++){
		now.fs -= (brr[i]-t);
		now.sc += (brr[i]-t);
		t = brr[i];
		if(now.sc<arr[i].fs||now.fs>arr[i].sc)flag = false;
		now.fs = max(now.fs,arr[i].fs);
		now.sc = min(now.sc,arr[i].sc);
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
