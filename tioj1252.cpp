#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> st;
int n;

void solve(){
	st.clear();
	st.insert(make_pair(0ll,-1ll));
	pll ans = make_pair(0,0);
	ll pref = 0;
	for(int i = 0;i<n;i++){
		char c;
		ll k;
		cin>>c>>k;
		if(c == 's')pref += k;
		else pref -= k;
		auto it = st.lower_bound(make_pair(pref-1,INT_MAX));
		if(it == st.end())ans.fs += i+1;
		else ans.fs += st.order_of_key(*it);
		st.insert(make_pair(pref,i));
		ans.sc = max(ans.sc,pref-st.begin()->fs);
	}
	cout<<ans.fs<<' '<<ans.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n){
		if(!n)break;
		solve();
	}
}
