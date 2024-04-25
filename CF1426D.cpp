#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 2e5+10;
ll arr[mxn];
ll n;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i= 1;i<=n;i++)cin>>arr[i],arr[i] += arr[i-1];
	map<ll,ll> pre;
	pre[0] = 0;
	vector<pll> v;
	for(int i = 1;i<=n;i++){
		if(pre.find(arr[i]) != pre.end()){
			v.push_back({pre[arr[i]]+1,i-1});
		}
		pre[arr[i]] = i;
	}
	sort(v.begin(),v.end(),[](pll &a,pll &b){
			return a.sc<b.sc;});
	vector<pll> vv;
	ll l = -1;
	for(auto &i:v){
		if(l<i.fs){
			vv.push_back(i);
			l = i.fs;
		}
	}
	ll ans = 0;
	l = -1;
	for(auto &i:vv){
		if(l<i.fs){
			ans++;
			l = i.sc;
		}
	}
	cout<<ans;
}
