#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

typedef tree<ll,null_type,greater<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int mxn = 2e5+10;
ll n;
ll arr[mxn];
multiset<ll> st,dif;

inline void add(ll k){
	auto it = st.lower_bound(k);
	if(it != st.end()&&it != st.begin()){
		dif.erase(dif.find(*it-*prev(it)));
	}
	if(it != st.end())dif.insert(*it-k);
	if(!st.empty()&&it != st.begin())dif.insert(k-*prev(it));
	st.insert(k);
}

inline void del(ll k){
	auto it = st.lower_bound(k);
	assert(it != st.end());
	if(next(it) != st.end()&&it != st.begin()){
		dif.insert(*next(it)-*prev(it));
	}
	if(next(it) != st.end())dif.erase(dif.find(*next(it)-k));
	if(it != st.begin())dif.erase(dif.find(k-*prev(it)));
	st.erase(st.find(k));
	return;
}

void solve(){
	st.clear();dif.clear();
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		add(arr[i]);
	}
	int q;
	cin>>q;
	while(q--){
		ll a,b;
		cin>>a>>b;
		if(n == 1){
			arr[0] = b;
			cout<<arr[0]<<' ';
			continue;
		}
		a--;
		del(arr[a]);
		arr[a] = b;
		add(arr[a]);
		cout<<*st.rbegin()+*dif.rbegin()<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
