#include <bits/stdc++.h>
using namespace std;

#define ll long long
map<ll,ll> mp;
map<ll,set<ll>> del,used;
set<ll> st;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	st.insert(0);
	int q;
	cin>>q;
	while(q--){
		char c;
		cin>>c;
		ll x;
		cin>>x;
		if(c == '+'){
			st.insert(x);
			for(auto &j:used[x])del[j].erase(x);
		}
		else if(c == '-'){
			for(auto &j:used[x]){
				if(mp[j]>=x)del[j].insert(x);
			}
			st.erase(x);
		}
		else{
			while(st.find(mp[x])!=st.end())used[mp[x]].insert(x),mp[x] += x;
			if(!del[x].empty()){
				cout<<*del[x].begin()<<'\n';
			}
			else cout<<mp[x]<<'\n';
		}
	}
}
