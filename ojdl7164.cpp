#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld double
#define _all(T) T.begin(),T.end()
const ll mxn = 3e6+10;
const ld eps = 1e-8;
ll a[mxn],b[mxn];
ll n,k;
ld tmp[mxn];

ld f(ld now){
	fill(tmp,tmp+mxn,0.0);
	for(int i = 0;i<n;i++)tmp[i] = b[i]-now*a[i];
	nth_element(tmp,tmp+k,tmp+n,greater<ld>());
	ld s = 0;
	for(int i = 0;i<k;i++)s += tmp[i];
	return s;	
}
int main(){
	io
	cin>>n>>k;
	ld l = 0,r = INT_MAX;
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++)cin>>b[i];
	while(r-l>eps){
		ld mid = (l+r)/2;
		if(f(mid)>0)l = mid;
		else r = mid;
	}
	cout<<fixed<<setprecision(8)<<l;
}

