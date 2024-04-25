#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
vector<pll> v;
pll arr[mxn];
pll range[mxn];
ll n,h;

inline ll calc(pll p,ll t){
	return p.sc*min(t,p.fs);
}

inline ll check(ll tar){
	ll sum = 0;
	for(int i = 0;i<n;i++){
		ll L = min(tar+1-range[i].fs,range[i].sc-range[i].fs);
		L = max(L,0ll);
		sum += L*(L+1)/2*v[i].sc;
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>h;
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs>>arr[i].sc;
	}
	sort(arr,arr+n);
	for(int i = 0;i<n;i++){
		if(!v.empty()&&arr[i].sc>=v.back().sc)v.pop_back();
		v.push_back(arr[i]);
	}
	range[0].fs = 0;
	for(int i = 1;i<v.size();i++){
		ll l = 0,r = 1e9;
		while(l != r){
			ll mid = (l+r)>>1;
			if(calc(v[i-1],mid)<calc(v[i],mid))r = mid;
			else l = mid+1;
		}
		range[i-1].sc = l;
		range[i].fs = l;
	}
	range[v.size()-1].sc = 1e18;
	for(int i = 0;i<v.size();i++){
		cout<<v[i].fs<<' '<<v[i].sc<<":"<<range[i].fs<<','<<range[i].sc<<endl;
	}
	ll l = 0,r = 1e9;
	while(l != r){
		ll mid = (l+r)>>1;
		if(check(mid)>=h)r = mid;
		else l = mid+1;
		cout<<l<<' '<<mid<<' '<<r<<":"<<check(mid)<<endl;
	}
	cout<<l;
}
