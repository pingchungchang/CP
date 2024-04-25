#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	set<int> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		st.insert(k);
	}
	int ans = 0;
	while(!st.empty()){
		auto it = *st.rbegin();
		st.erase(it);
		if(it&1)continue;
		else{
			st.insert(it/2);
			ans++;
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
