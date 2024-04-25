#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	ll arr[n];
	ll req[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++)req[i] = arr[i];
	vector<pll> v;
	sort(arr,arr+n);
	for(auto &i:arr){
		if(v.empty()||v.back().fs != i)v.push_back({i,1});
		else v.back().sc++;
	}
	ll cnt = 0,pref = 0,suf = 0;
	ll ans[v.size()];
	for(auto &i:v)suf += i.fs*i.sc;
	for(int i = 0;i<v.size();i++){
		cnt += v[i].sc;
		pref += v[i].fs*v[i].sc;
		suf -= v[i].fs*v[i].sc;
		ans[i] = cnt*(v[i].fs+1)-pref+suf-(v[i].fs-1)*(n-cnt);
	}
	for(auto &i:req){
		auto it = lower_bound(v.begin(),v.end(),make_pair(i,-1LL))-v.begin();
		cout<<ans[it]<<' ';
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
