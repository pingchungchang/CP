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

vector<ll> v;
int n,m;

bool f(ll now){
	int cnt = 1;
	ll x = 0;
	for(auto &i:v){
		x += i;
		if(x>now){
			cnt++;
			x = i;
		}
		if(i>now)return false;
	}
	if(cnt<=n)return true;
	else return false;
}
int main(){
	io
	cin>>m>>n;
	v = vector<ll>(m);
	for(auto &i:v)cin>>i;
	ll l = 0,r = 1e18;
	while(l != r){
		ll mid = (l+r)/2;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l;
}

