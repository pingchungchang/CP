#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll inf = 1e18;
set<ll> st;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	ll ans = inf;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		auto it = st.lower_bound(k);
		if(it != st.end())ans = min(ans,abs(*it-k));
		if(it != st.begin())it--;
		ans = min(ans,abs(*it-k));
	}
	cout<<ans;
}
