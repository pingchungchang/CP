#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

int n,m,k;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ordered_set st;


tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> st;
st.insert(1);
st.erase(1);
st.find(1);
auto it = st.find(3);


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 0;i<n;i++){
		st.insert(i);
		st.insert(i+n);
	}
	m--;
	int sz = n;
	int now = 0;
	while(k--){
		int pos = st.order_of_key(now);
		auto boom = st.find_by_order(pos+m%sz);
		int num = *boom;
		now = *next(boom)%n;
		num %= n;
		st.erase(num);
		st.erase(num+n);
		sz--;
	}
	cout<<now+1;
}
