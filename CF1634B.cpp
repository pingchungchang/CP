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
	ll n,x,y;
	cin>>n>>x>>y;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		y ^=k;
	}
	if((y^x)%2 == 0){
		cout<<"Alice\n";
	}
	else cout<<"Bob\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

