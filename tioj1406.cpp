#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int n;
const ll mxn = 1e5+10;
pll arr[mxn];
pll brr[mxn];

bool f(ll tar){
	ll p = 0;
	for(int i = 1;i<=n;i++){
		ll tmp = arr[i].sc-tar;
		if(p>=0)p = max(0LL,p-(arr[i].fs-arr[i-1].fs));
		else p -= arr[i].fs-arr[i-1].fs;
		if(tmp>=0){
			p += tmp;
		}
		else{
			p += tmp;
		}
	}
	return p>=0;
}


void solve(){
	for(int i = 1;i<=n;i++){
		cin>>arr[i].fs>>arr[i].sc;
	}
	ll l = 0, r = 1e12;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(f(mid))l = mid;
		else r= mid-1;
	}
	cout<<l<<'\n';
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
