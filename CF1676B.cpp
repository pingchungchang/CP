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
	int n;
	cin>>n;
	ll nn = n;
	ll sum = 0;
	ll sm = INT_MAX;
	while(n--){
		ll k;
		cin>>k;
		sm = min(sm,k);
		sum += k;
	}
	cout<<sum-sm*nn<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

