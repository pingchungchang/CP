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
	ll n,x;
	cin>>n>>x;
	map<ll,ll> mp[2];
	bool roll = 0;
	mp[roll][1] = 1;
	for(int i = 1;i<=n;i++){
		roll ^= 1;
		mp[roll].clear();
		int C;
		cin>>C;
		while(C--){
			ll k;
			cin>>k;
			for(auto &j:mp[roll^1]){
				if(__int128(j.fs)*k>1e18)continue;
				mp[roll][j.fs*k]+=j.sc;
			}
		}
	}
	cout<<mp[roll][x];
}
