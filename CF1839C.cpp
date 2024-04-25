#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;



void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	if(arr[n-1] != 0){
		cout<<"NO\n";
		return;
	}
	vector<int> ans;
	bool done[n] = {};
	int p = n-1;
	int flip = 0;
	while(p>=0){
		while(p>=0&&(arr[p]+flip)%2 == 0){
			p--;
		}
		flip++;
		ans.push_back(p+1);
		done[p+1] = true;
		//for(int i = p+1;!done[i];i++)done[i] = true,ans.push_back(i);
	}
	for(int i = 0;i<n;i++)if(!done[i])ans.push_back(i);
	//for(int i = n-1;i>=0;i--)if(!done[i])ans.push_back(i);
	//for(auto &i:ans)cout<<i<<',';cout<<'\n';
	reverse(ans.begin(),ans.end());
	ordered_set st;
	cout<<"YES\n";
	for(auto &i:ans){
		auto it = st.upper_bound(i);
		cout<<st.order_of_key(i)<<' ';
		/*
		if(it == st.end()){
			cout<<st.size()<<' ';
		}
		else cout<<st.order_of_key(*it)<<' ';

	   */
		st.insert(i);
	}
	cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
