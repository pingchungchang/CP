#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<pii> v[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		v[a].push_back({b,i});
	}
	set<pii> st;
	vector<int> ans;
	for(int i = 1;i<mxn;i++){
		for(auto &j:v[i]){
			st.insert(j);
		}
		while(st.size()>k){
			ans.push_back(st.rbegin()->sc);
			st.erase(*st.rbegin());
		}
		while(!st.empty()&&st.begin()->fs == i)st.erase(*st.begin());
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';
	return 0;
}
