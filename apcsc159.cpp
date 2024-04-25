#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

bool cmp(pll a,pll b){
	return a.fs-a.sc<b.fs-b.sc;
}
int main(){
	io
	ll n,k;
	cin>>n>>k;
	vector<pll> v(n);
	for(int i= 0;i<n;i++)cin>>v[i].fs;
	for(int i = 0;i<n;i++)cin>>v[i].sc;
	sort(_all(v),cmp);
	ll l = 0,r = n;
	while(l != r){
		ll mid = (l+r+1)/2;
		ll total = 0;
		for(ll i = 0;i<mid;i++){
			total += v[i].sc;
		}
		for(ll i =mid;i<n;i++)total += v[i].fs;
		if(total>=k)l = mid;
		else r = mid-1;
	}
	cout<<l;
}

