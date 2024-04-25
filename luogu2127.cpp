#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
bitset<mxn> vis;
vector<ll> all;
ll arr[mxn];
vector<tlll> v;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		all.push_back(arr[i]);
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for(int i = 0;i<n;i++){
		arr[i] = lower_bound(all.begin(),all.end(),arr[i])-all.begin();
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		if(vis[i])continue;
		ll sz = 0;
		int now = i;
		ll s = 0;
		do{
			sz++;
			s += all[now];
			now = arr[now];
		}while(now != i);
		ll sm = 1e9;
		do{
			sm = min(sm,all[now]);
			vis[now] = true;
			now = arr[now];
		}while(!vis[now]);
		v.push_back(make_tuple(sm,sz,s));
	}
	sort(v.begin(),v.end());
	ans += get<2>(v[0])+get<0>(v[0])*(get<1>(v[0])-2);
	for(int i = 1;i<v.size();i++){
		ans += min(get<0>(v[0])*(get<1>(v[i]))+get<2>(v[i])+get<0>(v[0])+get<0>(v[i]),get<2>(v[i])+get<0>(v[i])*(get<1>(v[i])-2));
	}
	cout<<ans;
}
