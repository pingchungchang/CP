#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	vector<int> v = {6,10,14,15,21,22,33,34,35};
	int n;
	cin>>n;
	for(int i = 0;i<(1<<v.size());i++){
		if(__builtin_popcount(i) != 3)continue;
		set<int> st;
		int sum = 0;
		for(int j = 0;j<v.size();j++){
			if(i&(1<<j))sum += v[j],st.insert(v[j]);
		}
		if(n<=sum)continue;
		if(st.find(n-sum) != st.end())continue;
		cout<<"YES\n";
		for(auto &j:st)cout<<j<<' ';cout<<n-sum<<'\n';
		return;
	}
	cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
