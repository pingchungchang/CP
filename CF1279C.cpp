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

const int mxn = 1e5+10;
int arr[mxn],brr[mxn];
ordered_set st;

void solve(){
	st.clear();
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		arr[k] = i;
		st.insert(i);
	}
	ll ans = 0;
	int r = 0;
	for(int i = 1;i<=m;i++){
		int k;
		cin>>k;
		if(r<arr[k]){
			ans += st.order_of_key(arr[k])*2+1;
			r = arr[k];
		}
		else ans++;
		st.erase(arr[k]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
