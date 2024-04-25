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
int main(){
	io
	ll n,k;
	cin>>n>>k;
	vector<ll> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	ll ans =0;
	for(int i = n-1;i>=0;i--){
		ans += k/v[i];
		k %= v[i];
	}
	cout<<ans;
}

