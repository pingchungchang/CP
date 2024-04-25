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

vector<pll> v;
ll n;
bool f(ll x){
	ll total = 0;
	for(auto &i:v){
		if(i.fs>x)total += i.sc;
	}
	if(total>x)return false;
	else return true;
}
void solve(){
	cin>>n;
	v = vector<pll>(n);
	for(auto &i:v)cin>>i.fs;
	for(auto &i:v)cin>>i.sc;
	ll l = 0,r = 2e9+10;
	while(l != r){
		ll mid = (l+r)/2;
//		cout<<mid<<' '<<f(mid)<<endl;
		if(f(mid)){
			r = mid;
		}
		else l = mid+1;
	}
	cout<<l<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

