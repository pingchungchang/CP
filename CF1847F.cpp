#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	int q;
	cin>>n>>q;
	int pre[32] = {};
	memset(pre,-1,sizeof(pre));
	int arr[n*2];
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = n;i<n*2;i++)arr[i] = arr[i-n];
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=30;j++){
			if((1LL<<j)&arr[i])pre[j] = i;
		}
	}
	vector<pll> v;
	for(int i = 0;i<n;i++)v.push_back({i+1,arr[i]});
	for(int i = n+1;i<n*2;i++){
		vector<pll> vv = {make_pair(i-n+1,arr[i])};
		for(int j = 0;j<=30;j++){
			if((1LL<<j)&arr[i])continue;
			if(pre[j] == -1)continue;
			ll p = pre[j],len = i-p+1;
			/*
			cout<<i<<":"<<p<<' '<<len<<',';

		   */
			assert(len>0);
			ll pos = (len-1)*(n-1)+1+(i-n);
			vv.push_back({pos,arr[p]});
		}
		for(int j = 0;j<=30;j++){
			if(arr[i]&(1LL<<j))pre[j] = i;
		}
		sort(vv.begin(),vv.end());
		for(int j = 1;j<vv.size();j++)vv[j].sc = vv[j-1].sc|vv[j].sc;
		/*
		cout<<i<<":";
		for(auto &j:vv)cout<<j.fs<<','<<j.sc<<' ';cout<<'\n';

	   */
		for(auto &j:vv)v.push_back(j);
	}
	vector<pll> tar;
	sort(v.begin(),v.end());
	for(auto &i:v){
		if(tar.empty()||tar.back().sc<i.sc)tar.push_back(i);
	}
	for(auto &i:tar)swap(i.fs,i.sc);
	//for(auto &i:tar)cout<<i.fs<<','<<i.sc<<' ';cout<<'\n'<<'\n';
	while(q--){
		ll k;
		cin>>k;
		auto it = lower_bound(tar.begin(),tar.end(),make_pair(k+1,-1LL));
		if(it == tar.end()){
			cout<<"-1\n";
		}
		else cout<<it->sc<<'\n';
	}
	return;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
