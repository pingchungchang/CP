#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll s,t,n;
	cin>>s>>t>>n;
	ll total = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		total += k;
	}
	ll ans = 0;
	ans += min(total,t/5)*s*7/10;
	total = max(0LL,total-t/5);
	ans += min(total,t/5)*s*8/10;
	total = max(0LL,total-t/5);
	ans += min(total,t/5)*s*9/10;
	total = max(0LL,total-t/5);
	ans += total*s;
	cout<<ans-s*t*3/10;
}

