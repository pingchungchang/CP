#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	ll n,k;
	cin>>n>>k;
	ll add = k/n;
	while(add > 0){
//		cout<<add<<';'<<'\n';
		ll tmp = add;
		k += add;
		add = k/n-(k-add)/n;
	}
	cout<<k<<"\n";
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

