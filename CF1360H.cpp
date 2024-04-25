#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	vector<ll> v;
	ll n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		ll tmp = 0;
		for(int j = 0;j<m;j++){
			if(s[j] == '1')tmp |= (1LL<<(m-1-j));
		}
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	ll len = (1LL<<m)-n;
	ll l = 0,r = (1LL<<m)-1;
	while(l != r){
		ll mid = (l+r+1)>>1;
		auto pos = upper_bound(v.begin(),v.end(),mid)-v.begin();
		if((len-1)/2 >= mid-pos)l = mid;
		else r = mid-1;
	}
	set<ll> st;
	for(auto i:v)st.insert(i);
	while(st.find(l) != st.end())l--;
	while(st.find(r) != st.end())r++;
	auto pos = upper_bound(v.begin(),v.end(),l)-v.begin();
	ll ans;
	if((len-1)/2 == l-pos)ans = l;
	else ans = r;
	//cout<<ans<<'\n';
	for(int i = m-1;i>=0;i--){
		if((1LL<<i)&ans)cout<<1;
		else cout<<0;
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
