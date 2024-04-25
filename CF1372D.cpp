#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	ll arr[n];
	ll total = 0;
	for(auto &i:arr)cin>>i,total += i;
	ll ans = 0;
	pll pref[n],suf[n];
	pref[0].fs = arr[0];
	pref[0].sc = 0;
	for(int i = 1;i<n;i++){
		pref[i] = pref[i-1];
		if(i&1)pref[i].sc += arr[i];
		else pref[i].fs += arr[i];
	}
	suf[n-1].fs = arr[n-1];
	suf[n-1].sc = 0;
	for(int i = n-2;i>=0;i--){
		suf[i] = suf[i+1];
		if(i&1)suf[i].sc += arr[i];
		else suf[i].fs += arr[i];
	}
	ans = max({total-pref[n-1].sc,total-suf[2].fs,total-pref[n-3].fs});
	/*
	for(auto &i:pref)cout<<i.fs<<' ';cout<<'\n';
	for(auto &i:pref)cout<<i.sc<<' ';cout<<'\n';
	for(auto &i:suf)cout<<i.fs<<' ';cout<<'\n';
	for(auto &i:suf)cout<<i.sc<<' ';cout<<'\n';
	cout<<ans;return;

   */
	for(int i = 2;i<=n-2;i++){
		if(i&1)ans = max(ans,total-pref[i-2].sc-suf[i+1].fs);
		else ans = max(ans,total-pref[i-2].fs-suf[i+1].sc);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
/*
1 2 3 4 5 6 7
^   ^   ^
*/





