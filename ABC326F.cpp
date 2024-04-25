#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


int n;
string ans,s;
ll tar[2];
vector<ll> v[2];
ll arr[88];

ll solve(ll val,vector<ll> &arr){
	vector<ll> l,r;
	int p=0;
	for(;p+p<arr.size();p++)l.push_back(arr[p]);
	int cut = p;
	for(;p<arr.size();p++)r.push_back(arr[p]);
	vector<pll> vv;
	for(int i = 0;i<(1ll<<l.size());i++){
		ll sum = 0;
		for(int j = 0;j<l.size();j++)if(i&(1ll<<j))sum += l[j];else sum -= l[j];
		vv.push_back({sum,i});
	}
	sort(vv.begin(),vv.end());
	for(ll i = 0;i<(1ll<<r.size());i++){
		ll sum = 0;
		for(int j = 0;j<r.size();j++)if(i&(1ll<<j))sum += r[j];else sum -= r[j];
		auto it = lower_bound(vv.begin(),vv.end(),make_pair(val-sum,-1ll));
		if(it != vv.end()&&it->fs+sum == val){
			return it->sc|(i<<cut);
		}
	}
	return -1ll;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>tar[0]>>tar[1];
	ans = string(n,'#');
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		arr[i] = k;
		v[i&1].push_back(k);
	}
	auto re = solve(tar[1],v[0]);
	if(re == -1){
		cout<<"No";
		return 0;
	}
	for(int i = 0;i<v[0].size();i++)if(re&(1ll<<i))ans[i*2] = 'U';else ans[i*2] = 'D';
	re = solve(tar[0],v[1]);
	if(re == -1){
		cout<<"No";
		return 0;
	}
	for(int i = 0;i<v[1].size();i++)if(re&(1ll<<i))ans[i*2+1] = 'R';else ans[i*2+1] = 'L';
	s = ans;
	if(ans[0] == 'U')s[0] = 'L';
	else s[0] = 'R';
	for(int i = 0;i<n;i+=2)if(ans[i] == 'U')tar[1] -= arr[i];else tar[1] += arr[i];
	for(int i = 1;i<n;i+=2)if(ans[i] == 'R')tar[0] -= arr[i];else tar[0] += arr[i];
	assert(!tar[0]&&!tar[1]);
	for(int i = 1;i<n;i++){
		if(ans[i] == 'L')if(ans[i-1] == 'U')s[i] = 'L';else s[i] = 'R';
		if(ans[i] == 'R')if(ans[i-1] == 'U')s[i] = 'R';else s[i] = 'L';
		if(ans[i] == 'U')if(ans[i-1] == 'L')s[i] = 'R';else s[i] = 'L';
		if(ans[i] == 'D')if(ans[i-1] == 'L')s[i] = 'L';else s[i] = 'R';
	}
	cout<<"Yes\n";
	cout<<s;
}
