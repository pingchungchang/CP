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
void solve(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	vector<ll> va,vb;
	for(ll i = 1;i*i<=a;i++){
		if(a%i == 0){
			va.push_back(i);
			va.push_back(a/i);
		}
	}
	for(ll i = 1;i*i<=b;i++){
		if(b%i == 0){
			vb.push_back(i);
			vb.push_back(b/i);
		}
	}
	for(auto ta:va){
		for(auto tb:vb){
			ll k = ta*tb;
			ll x = a/k*k;
			while(x<=a)x+=k;
			ll k1 = a/ta*b/tb;
			ll y = b/k1*k1;
			while(y<=b)y += k1;
			if(x<=c&&y<=d){
				cout<<x<<' '<<y<<'\n';
				return;
			}
		}
	}
	cout<<"-1 -1\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

