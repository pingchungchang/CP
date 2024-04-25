#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	ll n,a,b;
	cin>>n>>a>>b;
	ll arr[n];
	set<ll> st;
	for(int i = 1;i<=n;i++)st.insert(i);
	arr[0] = a;
	st.erase(a);
	st.erase(b);
	arr[n-1] = b;
	for(int i= 1;i<n-1;i++){
		arr[i] = *st.rbegin();
		st.erase(*st.rbegin());
	}
	if(*min_element(arr,arr+n/2) == a&&*max_element(arr+n/2,arr+n) == b){
		for(auto i:arr)cout<<i<<' ';cout<<'\n';
	}
	else cout<<-1<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

