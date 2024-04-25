#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<ll,ll> mp;
	ll n,l,r;
	cin>>n>>l>>r;
	mp[0] = 1;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		for(auto it = mp.rbegin();it != mp.rend();it++){
			if(mp.count(it->first+k) == 0){
				mp[it->first+k] = it->second;
			}
			else mp[it->first+k]+= it->second;
		}
	}
//	for(auto it = mp.begin();it != mp.end();it++){
//		cout<<it->first<<' '<<it->second<<endl;
//	}
//	return 0;
	mp[0]--;
	ll now = l;
	ll pref = 0;
	for(auto it = mp.rbegin();it != mp.rend();it++){
		pref+= it->second;
		if(pref>=now){
			while(now<=r&&pref>=now){
				cout<<it->first<<' ';
				now++;
			}
		}
		if(now >r)return 0;
	}
	
}
