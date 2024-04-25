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
#pragma GCC optimize("O3")
const ll mod = 998244353;
const ll mx1 = 1e9+10;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
	ll operator()(ll x) const { return x ^ RANDOM; }
};
gp_hash_table<ll, gp_hash_table<ll, gp_hash_table<ll, ll, chash>, chash>, chash> dp;

#define map unordered_map

int main(){
	io
	ll n,m;
	cin>>n>>m;
	pll dir[3];
	for(int i = 0;i<3;i++)cin>>dir[i].fs>>dir[i].sc;
//	map<ll,map<ll,map<ll,ll>>> dp;
	unordered_set<ll> no;
	for(int i = 0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		no.insert(mx1*a+b);
	}
	dp[0][0][0] = 1;
	for(int asd = 0;asd<n;asd++){
//		cout<<asd<<endl;
		for(auto &j:dp[asd]){
			for(auto &k:j.sc){
				pll pos = {j.fs,k.fs};
				ll times = asd;
				for(auto nn:dir){
					pll nxt = {nn.fs+pos.fs,nn.sc+pos.sc};
					if(no.find(nxt.fs*mx1+nxt.sc) == no.end()){
						ll tmp = dp[asd+1][nxt.fs][nxt.sc]+k.sc;
						if(tmp>mod)tmp -= mod;
						dp[asd+1][nxt.fs][nxt.sc] = tmp;
					}
				}
			}
		}
	}
	ll total = 0;
	for(auto &i:dp[n]){
		for(auto &j:i.sc){
			total += j.sc;
			if(total>mod)total -= mod;
		}
	}
	cout<<total;
	return 0;
}


