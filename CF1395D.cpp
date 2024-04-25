#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,d,m;
	cin>>n>>d>>m;
	vector<ll> big,small;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(k>m)big.push_back(k);
		else small.push_back(k);
	}
	sort(big.begin(),big.end());
	big.push_back(0);
	reverse(big.begin(),big.end());
	sort(small.begin(),small.end());
	small.push_back(0);
	reverse(small.begin(),small.end());
	for(int i = 1;i<big.size();i++)big[i] += big[i-1];
	ll pref = 0;
	for(int i= 0;i<small.size();i++){
		pref += small[i];
		ll C = (n-i+d)/(d+1);
		C = min(C,(ll)big.size()-1);
		//cout<<i<<":"<<C<<' '<<pref<<' '<<big[C]<<'\n';
		ans = max(ans,big[C]+pref);
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
