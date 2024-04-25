#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

int n,q;
set<int> st;
multiset<ll> seg;

void add(int k){
	auto it = st.lower_bound(k);
	if(it != st.begin()&&it != st.end()){
		auto l = prev(it);
		seg.erase(seg.find(*it-*l));
	}
	it = st.insert(k).fs;
	if(it != st.begin())seg.insert(*it-*prev(it));
	if(next(it) != st.end())seg.insert(*next(it)-*it);
	return;
}

void del(int k){
	st.erase(k);
	auto it = st.lower_bound(k);
	if(it != st.begin()&&it != st.end())seg.insert(*it-*prev(it));
	if(it != st.end())seg.erase(seg.find(*it-k));
	if(it != st.begin())seg.erase(seg.find(k-*prev(it)));
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		add(k);
	}
	seg.insert(0);
	cout<<(st.empty()?0:*st.rbegin()-*st.begin()-*seg.rbegin())<<'\n';
	while(q--){
		int t,x;
		cin>>t>>x;
		if(t == 0)del(x);
		else add(x);
		cout<<(st.empty()?0:*st.rbegin()-*st.begin()-*seg.rbegin())<<'\n';
	}
}
