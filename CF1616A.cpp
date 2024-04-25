#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	map<int,int> mp;
	while(n--){
		int k;
		cin>>k;
		k = abs(k);
		mp[k]++;
	}
	int ans = mp.size();
	for(auto &i:mp)if(i.sc>1&&i.fs != 0)ans++;
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
