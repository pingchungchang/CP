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
	map<ll,ll> pref;
	ll arr[n];
	for(auto &i:arr)cin>>i,pref[i] += i;
	for(auto it = pref.begin();it != pref.end();it++){
		if(it == pref.begin())continue;
		it->sc += prev(it)->sc;
	}
	set<int> st;
	st.insert(pref.rbegin()->fs);
	for(auto it = pref.rbegin();it != pref.rend();it++){
		if(it == pref.rbegin())continue;
		if(it->sc < prev(it)->fs)break;
		st.insert(it->fs);
	}
	vector<int> ans;
	for(int i = 0;i<n;i++){
		if(st.find(arr[i]) != st.end())ans.push_back(i+1);
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
