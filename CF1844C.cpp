#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll inf = 1e18;

void solve(){
	int n;
	cin>>n;
	vector<ll> ev,od;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(i&1)od.push_back(k);
		else ev.push_back(k);
	}
	sort(ev.rbegin(),ev.rend());
	ll ans = ev[0];
	sort(od.rbegin(),od.rend());
	if(!od.empty())ans = max(ans,od[0]);
	pll sum = {0,0};
	for(auto &i:od){
		if(i>=0){
			sum.fs += i;
			sum.sc++;
		}
	}
	if(sum.sc)ans = max(ans,sum.fs);
	sum = {0,0};
	for(auto &i:ev){
		if(i>=0)sum.fs += i,sum.sc++;
	}
	if(sum.sc)ans = max(ans,sum.fs);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
