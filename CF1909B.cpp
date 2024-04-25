#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

#define int ll

void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	if(n == 2){
		cout<<(ll)1e18<<'\n';
		return;
	}
	for(ll i = 2;i<3e18;i<<=1){
		set<ll> st;
		for(auto &j:arr){
			st.insert(j%i);
		}
		if(st.size() == 2){
			cout<<i<<'\n';
			return;
		}
	}
	cout<<(ll)1e18<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
