#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin>>n;
	set<int> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		auto it = st.insert(k);
		int big = *st.rbegin();
		st.erase(it.fs,st.end());
		st.insert(big);
	}
	cout<<st.size()<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

