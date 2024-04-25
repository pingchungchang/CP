#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	vector<pll> v;
	int n;
	cin>>n;
	ll arr[n+1];
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>1)v.push_back({i,arr[i]});
	}
	ll pre = 1;
	for(auto &i:v){
		if((float)pre*i.sc>1e14){
			cout<<v[0].fs<<' '<<v.back().fs<<'\n';
			return;
		}
		pre *= i.sc;
	}
	arr[0] = 0;
	ll sum = 0;
	for(auto &i:arr)sum += i;
	tuple<ll,ll,ll> ans = make_tuple(sum,1,1);
	for(int i = 0;i<v.size();i++){
		ll pre = v[i].sc;
		for(int j = i+1;j<v.size();j++){
			pre *= v[j].sc;
			ll tans = pre;
			for(int k = 1;k<v[i].fs;k++)tans += arr[k];
			for(int k = v[j].fs+1;k<=n;k++)tans += arr[k];
			if(tans>get<0>(ans))ans = make_tuple(tans,v[i].fs,v[j].fs);
		}
	}
	cout<<get<1>(ans)<<' '<<get<2>(ans)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
