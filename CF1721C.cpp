#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	int n;
	cin>>n;
	ll a[n],b[n];
	for(auto &i:a)cin>>i;
	for(auto &i:b)cin>>i;
	pll ans[n];
	for(int i = 0;i<n;i++){
		auto pos = lower_bound(b,b+n,a[i])-b;
		ans[i].fs = b[pos]-a[i];
	}
	int mv[n] = {};
	mv[n-1] = n-1;
	for(int i = n-2;i>=0;i--){
		if(a[i+1]<=b[i])mv[i] = mv[i+1];
		else mv[i] = i;
	}
	for(int i = 0;i<n;i++)ans[i].sc = b[mv[i]]-a[i];
	for(auto &i:ans)cout<<i.fs<<' ';cout<<'\n';
	for(auto &i:ans)cout<<i.sc<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

