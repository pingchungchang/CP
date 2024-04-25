#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


ll n,k;
vector<ll> bit;
void modify(ll pos,ll val){
	for(;pos<=n;pos += pos&-pos)bit[pos] = min(bit[pos],val);
	return;
}
ll getval(ll p){
	ll ans = INT_MAX;
	for(;p>0;p -= p&-p)ans = min(ans,bit[p]);
	return ans;
}
void solve(){
	cin>>n>>k;
	vector<ll> v(n+1);
	bit = vector<ll>(n+1,INT_MAX);
	for(ll i = 1;i<=n;i++){
		cin>>v[i];
		modify(i,v[i]);
	}
	set<ll> st;
//	for(ll i = 1;i<=n;i++)cout<<getval(i)<<' ';cout<<';';
	for(ll i = 1;i<=n;i++)st.insert(getval(i));
//	for(auto i:st)cout<<i<<' ';cout<<';';
	for(ll i = 0;i<k;i++){
		ll x,d;
		cin>>x>>d;
		modify(x,v[x]-d);
		v[x] -= d;
		auto it1 = st.lower_bound(getval(x-1));
		auto it2 = st.lower_bound(getval(x));
		st.erase(it2,it1);
		if(getval(x) == v[x])st.insert(v[x]);
		cout<<st.size()<<' ';
	}
	cout<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

