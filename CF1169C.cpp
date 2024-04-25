#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<ll> v;
ll n,m;

bool f(ll val){
	ll pre = 0;
	for(auto i:v){
		if(i+val<pre)return false;
		if(i+val<m){
			pre = max(i,pre);
		}
		else{
			if((i+val)%m<pre)pre = max(i,pre);
		}
	}
	return true;
}
int main(){
	cin>>n>>m;
	v = vector<ll>(n);
	for(ll i= 0;i<n;i++)cin>>v[i];
	ll l = 0;
	ll r = 	m;
	while(l != r){
		ll mid = (l+r)/2;
		if(f(mid)){
			r = mid;
		}
		else l = mid+1;
	}
	cout<<l;
}

/*
10 10
5 0 5 9 4 6 4 5 0 0
*/

