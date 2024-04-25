#include <bits/stdc++.h>
using namespace std;

#define ll long long

set<ll> st;
int main(){
	ll n;
	cin>>n;
	ll k;
	st.insert(0);
	cin>>k;
	for(int i = 0;i<n;i++){
		ll tmp;
		cin>>tmp;
		auto it = st.begin();
		for(int j = 0;j<k&&it != st.end();j++){
			auto val = *it;
			st.insert(val+tmp);
			it = ++st.find(val);
		}
		while(st.size()>k+1)st.erase(*st.rbegin());
	}
	st.erase(0);
	while(st.size()>k)st.erase(*st.rbegin());
	cout<<*st.rbegin();
}
