#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

void solve(){
	ll n,k;
	cin>>n>>k;
	multiset<ll> st;
	vector<ll> v(n);
	ll ans = 0;
	for(ll i = 0;i<n;i++){
		cin>>v[i];
		st.insert(v[i]%k);
		ans += v[i]/k;
	}
	while(!st.empty()){
		if(*st.begin()+*st.rbegin()<k){
			st.erase(st.find(*st.begin()));
			st.erase(st.find(*st.begin()));
		}
		else{
			ans++;
			st.erase(st.find(*st.begin()));
			st.erase(st.find(*st.rbegin()));
		}
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

