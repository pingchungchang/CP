#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	multiset<int> st;
	for(int i = 0;i<n;i++)cin>>v[i];
	for(int i = 0;i<n;i++){
		int s;
		cin>>s;
		st.insert(s);
	}
	for(auto i:v){
		auto it = st.upper_bound(k-i);
		if(it == st.begin()){
			cout<<"No\n";
			return;
		}
		st.erase(--it);
	}
	cout<<"Yes\n";
	return;
}

int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

