#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>
typedef tree<pii,null_type,greater<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
map<int,int> mp;


void solve(){
	int n;
	cin>>n;
	int tar;
	cin>>tar;
	ordered_set st;
	for(int i =0 ;i<n;i++){
		int k;
		cin>>k;
		st.insert({k,mp[k]++});
	}
	int ans = 0;
	if(st.find(make_pair(tar,0)) == st.end()){
		ans = 1;
		st.insert(make_pair(tar,mp[tar]++));
	}
	while(st.find_by_order(st.size()/2)->fs != tar){
		st.insert(make_pair(tar,mp[tar]++));
		ans++;
	}
	cout<<ans;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
