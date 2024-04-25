#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 2e5+10;
const ll inf = 1e15;

ll n,k;
ll x[mxn],y[mxn];

inline ll calc(ll r){
	ll re = 0;
	for(int i = 0;i+i<n;i++){
		re += max(0ll,x[n-1-i]-x[i]-r);
		re += max(0ll,y[n-1-i]-y[i]-r);
		if(re>=inf)return inf;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i = 0;i<n;i++)cin>>x[i]>>y[i];
	sort(x,x+n);
	sort(y,y+n);
	ll l = 0,r = 1e9;
	while(l != r){
		ll mid = (l+r)>>1;
		if(calc(mid)<=k)r = mid;
		else l = mid+1;
	}
	cout<<l<<'\n';
}
