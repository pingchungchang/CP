#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	map<ll,ll> mp;
	bool flag = true;
	while(flag){
		flag = false;
		for(ll i = 2;i*i<=n;i++){
			if(n%i == 0){
				mp[i]++;
				n/=i;
				flag = true;
				break;
			}
		}
	}
	if(n != 1)mp[n]++;
	ll big = 0;
	for(auto &i:mp)big = max(big,i.sc);
	vector<ll> ans(big,1);
	for(auto &i:mp){
		int pt = big-1;
		while(i.sc--){
			ans[pt--] *= i.fs;
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
