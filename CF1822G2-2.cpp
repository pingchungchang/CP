#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

vector<int> primes;
const int mxn = sqrt(1e9)+1;
const int inf = 1e9;
bitset<mxn> isp;
int fac[1010];
pii pfac[3010];

void solve(){
	int n;
	cin>>n;
	unordered_map<int,int> mp;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	for(auto &i:arr)mp[i]++;
	ll ans = 0;
	for(auto &i:mp){
		ans += 1LL*i.sc*(i.sc-1)*(i.sc-2);
		int pt2 = 0;
		int now = i.fs;
		for(auto &j:primes){
			if(now%j == 0){
				pfac[pt2].fs = j;pfac[pt2].sc=0;
				while(now%j == 0)pfac[pt2].sc++,now/=j;
				pt2++;
			}
			if(now<j)break;
		}
		fac[0] = 1;
		int pt = 1;
		for(int j = 0;j<pt2;j++){
			int val = pfac[j].fs,cnt = pfac[j].sc;
			int p = val;
			int s = pt;
			while(cnt--){
				for(int k = 0;k<s;k++){
					fac[pt++] = fac[k]*p;
				}
				p*=val;
			}
		}
		//cout<<i.fs<<" "<<i.sc<<":";
		//for(auto &j:v)cout<<j<<' ';cout<<'\n';
		for(int j = 0;j<pt;j++){
			if(fac[j] == 1)continue;
			if(1LL*i.fs*fac[j]>inf)continue;
			if(mp.find(i.fs/fac[j]) != mp.end()&&mp.find(i.fs*fac[j]) != mp.end())
				ans += 1LL*mp[i.fs/fac[j]]*i.sc*mp[i.fs*fac[j]];
			//cout<<i.fs<<":"<<j<<'\n';
		}
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn;i++){
		if(!isp[i]){
			primes.push_back(i);
			for(int j = i+i;j<mxn;j+=i){
				isp[j] = true;
			}
		}
	}
	int t;cin>>t;
	while(t--)solve();
}
