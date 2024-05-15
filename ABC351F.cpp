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

template<typename T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
ordered_set<int> st;
ll ans = 0;
vector<pii> v;
int N;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++){
		int k;
		cin>>k;
		v.push_back(pii(k,i));
	}
	sort(v.rbegin(),v.rend());
	for(auto [val,pos]:v){
		ll coef = -((int)st.size()-st.order_of_key(pos))+(pos-1-st.order_of_key(pos));
		ans += coef*val;
		st.insert(pos);
	}
	cout<<ans<<'\n';
	return 0;
}
