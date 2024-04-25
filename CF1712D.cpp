#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1e5+10;
const ll big = 1e9;
const ll inf = 1e18;
vector<ll> arr;
ll n,k;

ll f(ll tar){
	ll del = (tar-1)/2;
	auto now = arr;
	ll re = 0;
	for(int i = 0;i<n;i++){
		if(now[i]<=del)re++,now[i] = big;
	}
	for(int i = 1;i<n;i++){
		if(min(now[i-1],now[i])>=tar)return re;
	}
	for(int i = 0;i<n;i++){
		if(now[i]>=tar)return re+1;
	}
	return re+2;
}

void solve(){
	cin>>n>>k;
	arr = vector<ll>(n,0);
	for(int i = 0;i<n;i++)cin>>arr[i];
	ll l = 0,r = 1e9;
	while(l != r){
		ll mid = (l+r+1)>>1;
		if(f(mid)<=k)l = mid;
		else  r = mid-1;
		//cout<<mid<<":"<<f(mid)<<'\n';
	}
	cout<<l<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
