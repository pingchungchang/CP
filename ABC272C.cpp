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
int main(){
	io
	ll n;
	cin>>n;
	vector<ll> ev,odd;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(k&1)odd.push_back(k);
		else ev.push_back(k);
	}
	ll ans = -1;
	sort(_all(ev));sort(_all(odd));
	if(ev.size()>1)ans = max(ans,ev.back()+*(++ev.rbegin()));
	if(odd.size()>1)ans = max(ans,odd.back()+*(++odd.rbegin()));
	cout<<ans;
}

