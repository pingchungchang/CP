#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,k;
	cin>>n>>k;
	set<ll> st;
	while(n--){
		ll tmp;
		cin>>tmp;
		st.insert(tmp);
	}
	for(auto it:st){
		if(st.find(it-k) != st.end()){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

