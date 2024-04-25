#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	vector<pii> v;
	for(auto &i:s){
		if(v.empty()||v.back().fs != i-'0')v.push_back({i-'0',1});
		else v.back().sc++;
	}
	vector<int> vv;
	for(auto &i:v)if(i.fs)vv.push_back(i.sc);
	sort(vv.rbegin(),vv.rend());
	ll ans = 0;
	for(int i = 0;i<vv.size();i+=2)ans += vv[i];
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
