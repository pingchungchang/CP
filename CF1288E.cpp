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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int mxn = 3e5+10;
ordered_set st;
int L = 0,R = 0;
int pos[mxn];
pii ans[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		st.insert(i);
		ans[i] = {i,i};
		pos[i] = i;
	}
	R = n;
	while(m--){
		int p;
		cin>>p;
		ans[p].fs = 1;
		ans[p].sc = max(ans[p].sc,(int)st.order_of_key(pos[p])+1);
		L--;
		st.erase(pos[p]);
		pos[p] = L;
		st.insert(pos[p]);
	}
	for(int i = 1;i<=n;i++){
		ans[i].sc = max(ans[i].sc,(int)st.order_of_key(pos[i])+1);
	}
	for(int i = 1;i<=n;i++)cout<<ans[i].fs<<' '<<ans[i].sc<<'\n';
}
