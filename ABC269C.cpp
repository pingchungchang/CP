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
int main(){
	vector<int> cnt;
	ll t;
	cin>>t;
	for(int i = 0;i<60;i++){
		if(t&(1LL<<i))cnt.push_back(i);
	}
//	for(auto &i:cnt)cout<<i<<' ';cout<<endl;
	for(int i = 0;i<(1LL<<cnt.size());i++){
		ll ans = 0;
		for(int j = 0;j<cnt.size();j++){
			if(i&(1LL<<j))ans ^= 1LL<<cnt[j];
		}
		cout<<ans<<'\n';
	}
	return 0;
	
}

