#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second
const int mxn = 1e6+10;
ll pos[mxn],arr[mxn],vals[mxn],newval[mxn];
bitset<mxn> vis;

main(){
    int n;
    cin>>n;
	for(int i = 1;i<=n;i++)cin>>vals[i];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		pos[k] = i;
	}
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		arr[i] = pos[arr[i]];
	}
	for(int i = 1;i<=n;i++)newval[pos[i]] = vals[i];
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		vis[arr[i]] = true;
		assert(arr[i]);
	}
	assert(vis.count() == n);
	vis.reset();
	vector<pll> cycles;
	for(int i = 1;i<=n;i++){
		if(vis[i])continue;
		vector<int> v;
		int now = i;
		do{
			v.push_back(now);
			vis[now] = true;
			now = arr[now];
		}while(!vis[now]);
		pll small = {newval[v[0]],v[0]};
		for(auto &i:v)small = min(small,make_pair(newval[i],i));
		for(auto &i:v){
			if(i == small.sc)continue;
			ans += newval[i]+small.fs;
		}
		cycles.push_back({small.fs,v.size()});
	}
	//for(auto &i:cycles)cout<<i.fs<<','<<i.sc<<endl;
	sort(cycles.begin(),cycles.end());
	for(int i = 1;i<cycles.size();i++){
		ll delta = (cycles[i].fs-cycles[0].fs)*(cycles[i].sc-1)-2LL*(cycles[0].fs+cycles[i].fs);
		if(delta>0)ans -= delta;
	}
	cout<<ans;
}
