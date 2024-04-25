#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 5e5+10;
int n,k,q;
multiset<ll> sl,sr;
ll arr[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>q;
	for(int i = 0;i<k;i++)sr.insert(0);
	for(int i = 0;i<n-k;i++)sl.insert(0);
	ll ans = 0;
	while(q--){
		int p,v;
		cin>>p>>v;
		if(sl.find(arr[p]) != sl.end())sl.erase(sl.find(arr[p]));
		else sr.erase(sr.find(arr[p])),ans -= arr[p];
		sl.insert(v);
		vector<ll> tmp;
		for(int i = 0;i<2;i++){
			if(!sr.empty()){
				tmp.push_back(*sr.begin());
				ans -= *sr.begin();
				sr.erase(sr.find(*sr.begin()));
			}
			if(!sl.empty()){
				tmp.push_back(*sl.rbegin());
				sl.erase(sl.find(*sl.rbegin()));
			}
		}
		sort(tmp.begin(),tmp.end());
		while(sr.size() != k){
			sr.insert(tmp.back());
			ans += tmp.back();
			tmp.pop_back();
		}
		while(!tmp.empty()){
			sl.insert(tmp.back());
			tmp.pop_back();
		}
		arr[p] = v;
		cout<<ans<<'\n';
	}
	return 0;
}
