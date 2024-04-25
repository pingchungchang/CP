#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	multiset<int> st;
	int ans[n] = {};
	int G = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	ans[0] = G = *st.rbegin();
	st.erase(st.find(*st.rbegin()));
	for(int i = 1;i<n;i++){
		pair<int,int> g = {-1,-1};
		for(auto &j:st){
			g = max(g,make_pair(__gcd(G,j),j));
		}
		ans[i] = g.sc;
		st.erase(st.find(g.sc));
		G = g.fs;
	}
	for(auto &i:ans){
		cout<<i<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
