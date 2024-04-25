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
	ll n;
	cin>>n;
	ll arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	set<ll> st;
	for(int i = n-1;i>=0;i--){
		if(st.find(arr[i]) != st.end()){
			cout<<i+1<<'\n';
			return;
		}
		st.insert(arr[i]);
	}
	cout<<0<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

