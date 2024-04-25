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
	ll n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		mp[k]++;
	}
	auto rit = mp.begin();
	ll ans =0,sum = 0;
	int C = 0;
	for(auto it = mp.begin();it != mp.end();it++){
		if(rit != mp.end()&&rit->fs<=it->fs){
			sum = it->sc;
			rit = it;
			rit++;
			C++;
		}
		while(rit != mp.end()&&(rit->fs-it->fs)<m){
			sum += rit->sc;
			rit++;
			C++;
		}
		ans =max(ans,sum);
		sum -= it->sc;
		//for(auto &j:mp)cout<<j.fs<<','<<j.sc<<' ';cout<<':';
		//cout<<it->fs<<":"<<(rit == mp.end()?-1:rit->fs)<<' '<<C<<endl;
	}
	cout<<ans;
}
