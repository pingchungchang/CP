#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mxn = 3e5+10;
ll cnt[mxn];
ll sum[mxn];
ll calc(ll ttt[],ll s,ll e){
	if(e>=mxn)e = mxn-1;
	if(s<=0)s = 1;
	return ttt[e]-ttt[s-1];
}
int main(){
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	for(auto &i:arr){
		cnt[i]++;
		sum[i] += i;
	}
	for(int i = 1;i<mxn;i++){
		cnt[i]+=cnt[i-1];
		sum[i] += sum[i-1];
	}
	ll ans = 1;
	for(ll i = 2;i<mxn;i++){
		ll total = 0;
		for(ll kk = 0;kk*i<mxn;kk++){
			total += (kk+1)*i*calc(cnt,kk*i+1,(kk+1)*i)-calc(sum,kk*i+1,(kk+1)*i);
		}
		if(total<=k)ans = i;
	}
	ll all = calc(sum,1,mxn);
	ll tmp = (all+k)/n;
	if(tmp>=mxn)ans = tmp;
	cout<<ans;
	//nx-all<=k
}