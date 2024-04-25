#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define pii pair<int,int>
#define fs first
#define sc second

typedef tree<pii,null_type,greater<pii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ordered_set st;
	map<int,int> mp;
	int k;
	int c = 0;
	while(cin>>k){
		st.insert(make_pair(k,mp[k]++));
		c++;
		if(c&1)cout<<st.find_by_order(c>>1)->fs<<'\n';
		else{
			cout<<((st.find_by_order(c>>1)->fs+st.find_by_order((c-1)>>1)->fs)>>1)<<'\n';
		}
	}
	return 0;
}
