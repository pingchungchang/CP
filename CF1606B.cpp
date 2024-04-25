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
	ll now = 1LL;
	ll ans = 0;
	n--;
	while(n>0&&now<=k){
		n -= now;
		ans++;
		now <<=1;
	}
	now = k;
	if(n<0)n = 0;
	ans += (n+k-1)/k;
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

