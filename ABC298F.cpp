#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
const ll mxn = 4e5+10;
ll segtree[mxn*4];
pair<pll,ll> arr[mxn];
vector<ll> allx,ally;
ll total[mxn];
vector<pll> change[mxn];

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now] += v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now] = max(segtree[now*2+1],segtree[now*2+2]);
}

int main(){
	ll n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs.fs>>arr[i].fs.sc>>arr[i].sc;
		allx.push_back(arr[i].fs.fs);
		ally.push_back(arr[i].fs.sc);
	}
	sort(allx.begin(),allx.end());
	sort(ally.begin(),ally.end());
	allx.erase(unique(allx.begin(),allx.end()),allx.end());
	ally.erase(unique(ally.begin(),ally.end()),ally.end());
	for(int i = 0;i<n;i++){
		arr[i].fs.fs = lower_bound(allx.begin(),allx.end(),arr[i].fs.fs)-allx.begin();
		arr[i].fs.sc = lower_bound(ally.begin(),ally.end(),arr[i].fs.sc)-ally.begin();
		change[arr[i].fs.fs].push_back({arr[i].fs.sc,arr[i].sc});
		total[arr[i].fs.fs] += arr[i].sc;
		modify(0,0,mxn,arr[i].fs.sc,arr[i].sc);
	}
	ll ans = 0;
	for(int i = 0;i<allx.size();i++){
		for(auto &j:change[i])modify(0,0,mxn,j.fs,-j.sc);
		ans = max(ans,total[i]+segtree[0]);
		for(auto &j:change[i])modify(0,0,mxn,j.fs,j.sc);
	}
	cout<<ans;
}
/*
r[a]+c[b]-mp[{a,b}]
*/
