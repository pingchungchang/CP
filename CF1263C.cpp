#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	set<ll> st;
	st.insert(0);
	st.insert(1);
	for(ll i = 1;i < n;i = n/(n/(i+1))){
		st.insert(n/i);
	}
	cout<<st.size()<<'\n';
	for(auto &i:st)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
