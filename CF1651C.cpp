#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
	int n;
	cin>>n;
	vector<ll> a(n),b(n);
	for(int i = 0;i<n;i++)cin>>a[i];
	for(int i = 0;i<n;i++)cin>>b[i];
	ll ans = 0LL;
	ll a1 = INT_MAX,a2 = INT_MAX,b1 = INT_MAX,b2 = INT_MAX;
	for(int i = 0;i<n;i++){
		a1 = min(a1,abs(a[0]-b[i]));
		a2 = min(a2,abs(a.back()-b[i]));
		b1 = min(b1,abs(b[0]-a[i]));
		b2 = min(b2,abs(b.back()-a[i]));
	}
	ans = a1+a2+b1+b2;
	ans = min(ans,abs(a.back()-b.back())+a1+b1);
	ans = min(ans,abs(a[0]-b[0])+a2+b2);
	ans = min(ans,abs(a.back()-b[0])+b2+a1);
	ans = min(ans,abs(a[0]-b.back())+a2+b1);
	ans = min(ans,abs(a.back()-b.back())+abs(a[0]-b[0]));
	ans = min(ans,abs(a[0]-b.back())+abs(a.back()-b[0]));
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}
