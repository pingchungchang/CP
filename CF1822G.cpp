#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#pragma GCC optimize("O3")
#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int sq = 1000;

void solve(){
	map<int,int> mp;
	int n;
	cin>>n;
	int mx = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k]++;
		mx = max(mx,k);
	}
	ll ans = 0;
	for(auto &i:mp)ans += 1LL*i.sc*(i.sc-1)*(i.sc-2);
	for(auto &i:mp){
		if(1LL*i.fs*sq>=mx){
			for(int j = 2;j*i.fs<=mx;j++){
				if(mp.find(i.fs*j)!= mp.end()&&i.fs%j == 0&&mp.find(i.fs/j) != mp.end())
					ans += 1LL*mp[i.fs*j]*i.sc*mp[i.fs/j];
			}
		}
		else{
			for(int j = 1;j*j<=i.fs;j++){
				if(i.fs%j != 0)continue;
				int tmp = j;
				if(tmp != 1&&1LL*tmp*i.fs<=mx&&mp.find(i.fs*tmp) != mp.end()&&mp.find(i.fs/tmp)!=mp.end()){
					ans += 1LL*mp[i.fs*tmp]*i.sc*mp[i.fs/tmp];
				}
				tmp = i.fs/j;
				if(tmp == j)continue;
				if(tmp != 1&&1LL*tmp*i.fs<=mx&&mp.find(i.fs*tmp) != mp.end()&&mp.find(i.fs/tmp)!=mp.end()){
					ans += 1LL*mp[i.fs*tmp]*i.sc*mp[i.fs/tmp];
				}
			}
		}
		//cout<<i.fs<<":"<<ans<<endl;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
