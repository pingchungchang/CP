#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	set<int> st;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int pref[n] = {};
	for(int i = n-1;i>=0;i--){
		if(st.find(arr[i]) == st.end())pref[i] = 1;
		st.insert(arr[i]);
	}
	for(int i = n-2;i>=0;i--)pref[i] += pref[i+1];
	st.clear();
	ll ans = 0;
	for(int i = 0;i<n;i++){
		if(st.find(arr[i]) == st.end())ans += pref[i];
		st.insert(arr[i]);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
