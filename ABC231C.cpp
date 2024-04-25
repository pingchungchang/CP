#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	map<int,int> mp;
	int n,q;
	cin>>n>>q;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k]++;
	}
	int pre = 0;
	for(auto it = mp.rbegin();it != mp.rend();it++){
		it->sc += pre;
		pre = it->sc;
	}
	while(q--){
		int k;
		cin>>k;
		auto it = mp.lower_bound(k);
		if(it == mp.end())cout<<"0\n";
		else cout<<it->sc<<'\n';
	}
	return 0;
}
