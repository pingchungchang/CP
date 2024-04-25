#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 5e4+10;
ll n,m,k;
pll arr[mxn];
ll ans = 0;
multiset<ll> ls1,ls2,rs1,rs2;//ls1:choose fs,ls2:choose sc,rs1:choose,rs2:pool
ll lsum,rsum;

inline ll calc(ll ca,ll cb){
	ls1.clear();ls2.clear();rs1.clear();rs2.clear();
	lsum = rsum = 0;
	for(int i = 1;i<=ca;i++){
		ls1.insert(arr[i].sc-arr[i].fs);
		lsum += arr[i].fs;
	}
	for(int i = ca+1;i<=n;i++){
		rs2.insert(arr[i].sc);
	}
	while(rs1.size() != cb){
		rsum += *rs2.begin();
		rs1.insert(*rs2.begin());
		rs2.erase(rs2.find(*rs2.begin()));
	}
	ll re = lsum+rsum;
	for(int i = ca+1;i<=ca+cb;i++){
		lsum += arr[i].fs;
		ls1.insert(arr[i].sc-arr[i].fs);
		if(rs2.find(arr[i].sc) != rs2.end())rs2.erase(rs2.find(arr[i].sc));
		else{
			rsum -= arr[i].sc;
			rs1.erase(rs1.find(arr[i].sc));
		}
		while(ls1.size()>ca){
			ls2.insert(-*ls1.begin());
			lsum += *ls1.begin();
			ls1.erase(ls1.find(*ls1.begin()));
		}
		while(rs1.size()+i>ca+cb){
			rs2.insert(*rs1.rbegin());
			rsum -= *rs1.rbegin();
			rs1.erase(rs1.find(*rs1.rbegin()));
		}
		assert(ls1.size()+ls2.size()+rs1.size() == ca+cb);
		re = min(re,lsum+rsum);
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>m;
	for(int i = 1;i<=n;i++){
		cin>>arr[i].sc>>arr[i].fs;
	}
	sort(arr+1,arr+n+1);
	ll tsum = 0;
	for(int i = 1;i<=k;i++){
		tsum += arr[i].fs;
		if(tsum<=m)ans = i;
	}
	ll l = 0, r = n-k;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(calc(k,mid)<=m)l = mid;
		else r = mid-1;
	}
	//cout<<l<<":"<<calc(k,l)<<endl;
	if(calc(k,l)<=m)ans = k+l;
	cout<<ans;
}
