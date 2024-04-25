#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<ll> v;

bool f(ll now){
	ll d = 0;
	for(auto i:v){
		if(now+d<i)return false;
		d = now+d-i;
	}
	return true;
}
void solve(){
	int n;
	cin>>n;
	v = vector<ll>(n);
	ll sum = 0;
	for(ll i = 0;i<n;i++){
		cin>>v[i];
		sum += v[i];
	}
	ll l = 0,r = INT_MAX;
	while(l != r){
		ll mid = (l+r)/2;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	ll lim = l;
	ll q;
	cin>>q;
	while(q--){
		ll tmp;
		cin>>tmp;
		if(tmp<lim){
			cout<<-1<<'\n';
		}
		else{
			cout<<(sum+tmp-1)/tmp<<'\n';
		}
	}
}
int main(){
	io
	int t  = 1;
	while(t--)solve();
}

