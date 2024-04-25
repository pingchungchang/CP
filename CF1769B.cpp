#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define int ll
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 110;
ll arr[mxn],pref[mxn];

pll calc(ll len,ll tar){
	ll l = 0,r = len;
	pll re = {-1,-1};
	while(l != r){
		ll mid = (l+r)>>1;
		if(mid*100/len < tar)l = mid+1;
		else r = mid;
	}
	re.fs = l;
	l = 0,r = len;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(mid*100/len>tar)r = mid-1;
		else l = mid;
	}
	re.sc = l;
	if(re.fs*100/len != tar)re = {-1,-1};
	return re;
}

bool inter(pll a,pll b){
	if(a.fs>b.fs)swap(a,b);
	return a.sc>=b.fs;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		pref[i] = pref[i-1]+arr[i];
	}
	vector<int> ans;
	for(int i = 0;i<=100;i++){
		pll range = calc(pref[n],i);
		if(range.fs == -1)continue;
		bool flag = false;
		for(int j = 1;j<=n;j++){
			auto tmp = calc(arr[j],i);
			if(tmp.fs == -1)continue;
			tmp.fs += pref[j-1],tmp.sc += pref[j-1];
			if(inter(tmp,range))flag = true;
		}
		if(flag)ans.push_back(i);
	}
	for(auto &i:ans)cout<<i<<'\n';
	return 0;
}
