#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

ll n,a,b;
vector<ll> v;

bool f(ll now){
	ll tmp = 0;
	for(auto &i:v){
		if(i<now){
			tmp -= (now-i+a-1)/a;
		}
		else{
			tmp += (i-now)/b;
		}
	}
	if(tmp>=0)return true;
	else return false;
}
int main(){
	cin>>n>>a>>b;
	v = vector<ll>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	ll l = 0,r = INT_MAX;
	while(l != r){
		ll mid = (l+r+1)/2;
		if(f(mid))l = mid;
		else r = mid-1;
	}
	cout<<r;
}

