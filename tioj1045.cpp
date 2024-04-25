#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
void solve(){
	ll ans = 0;
	vector<ll> all;
	vector<vector<ll>> req(n,vector<ll>(4));
	for(int i = 0;i<n;i++){
		for(int j =0;j<4;j++){
			cin>>req[i][j];
			all.push_back(req[i][j]);
		}
	}
	all.push_back(0);
	all.push_back(1e4);
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	
	vector<vector<vector<ll>>> change(all.size());
	for(int i = 0;i<n;i++){
		for(int j = 0;j<4;j++){
			req[i][j] = lower_bound(all.begin(),all.end(),req[i][j])-all.begin();
		}
		change[req[i][0]].push_back({req[i][1],req[i][3],1});
		change[req[i][2]].push_back({req[i][1],req[i][3],-1});
	}
	
//	for(int i = 0;i<change.size();i++){
//		for(int j = 0 ;j<change[i].size();j++){
//			for(int k = 0;k<3;k++){
//				cout<<change[i][j][k]<<' ';
//			}
//			cout<<',';
//		}
//		cout<<endl;
//	}
 
	vector<ll> vals(all.size(),0);
	for(int i = 0;i<all.size();i++){
		for(int j = 0;j<change[i].size();j++){
			ll s = change[i][j][0];
			ll e = change[i][j][1];
			vals[s] += change[i][j][2];
			vals[e] -= change[i][j][2];
		}
//		for(int j = 0;j<vals.size();j++)cout<<vals[j]<<' ';
//		cout<<endl<<endl;
		ll p = vals[0];
		if(i == all.size()-1)break;
		for(int j = 1;j<all.size();j++){
//			cout<<p<<' ';
			ans += (1LL<<p)*(all[j]-all[j-1])*(all[i+1]-all[i]);
			p += vals[j];
		}
//		cout<<endl;
	}
	cout<<ans<<'\n';
}
int main(){
	while(cin>>n){
		if(n == 0)return 0;
		solve();
	}
}
