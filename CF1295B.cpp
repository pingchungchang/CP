#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,x;
	cin>>n>>x;
	string s;
	cin>>s;
	if(x<0){
		for(auto &i:s)i = (i == '0'?'1':'0');
		x = -x;
	}
	int sum = 0;
	map<int,int> mp;
	for(auto &i:s){
		if(i == '0')sum++;
		else sum--;
		mp[sum]++;
	}
	if(sum == 0&&mp.begin()->fs<=x&&mp.rbegin()->fs>=x){
		cout<<"-1\n";
		return;
	}
	ll ans = 0;
	for(auto &i:mp){
		ll d = x-i.fs;
		if(d == 0)ans += i.sc;
		else if(sum<0&&d<0){
			if(abs(d)%abs(sum) == 0)ans += i.sc;
		}
		else if(sum>0&&d>0){
			if(d%sum == 0)ans += i.sc;
		}
	}
	if(x == 0)ans++;
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
