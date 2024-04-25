#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


ll calc(ll n,ll a,ll b){
	set<ll> st;
	for(int i = 1;i<=n;i++)if(i != a)st.insert(i);
	ll lim = a*b;
	ll re = 0;
	for(int i = n;i>=1;i--){
		if(i == b)continue;
		auto it = st.upper_bound(lim/i);
		if(it == st.begin())return 0;
		it--;
		re += i*(*it);
		st.erase(it);
	}
	return re;
}

void solve(){
	ll n;
	cin>>n;
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			ans = max(ans,calc(n,i,j));
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
