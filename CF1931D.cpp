#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	map<pii,int> mp;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		int ta = a-k%a,tb = k%b;
		if(ta == a)ta = 0;
		if(mp.find({ta,tb}) != mp.end())ans += mp[{ta,tb}];
		mp[{k%a,k%b}]++;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
