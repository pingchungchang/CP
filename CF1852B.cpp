#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	multiset<pii> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert({k,i});
	}
	int ans[n] = {};
	int r = n;
	for(int sh = 0;sh<n&&!st.empty();sh++){
		while(!st.empty()&&st.begin()->fs == sh){
			ans[st.begin()->sc] = -r;r--;
			st.erase(*st.begin());
		}
		if(!st.empty()&&st.rbegin()->fs-sh != r){
			cout<<"NO\n";
			return;
		}
		if(!st.empty()){
			ans[st.rbegin()->sc] = r;r--;
			st.erase(*st.rbegin());
		}
	}
	cout<<"YES\n";
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
