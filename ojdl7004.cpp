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
#pragma GCC optimize("O3")
main(){
	string s;
	int in;
	while((in = getchar()) != '\n'){
		s += in;
	}
	ll n = stoll(s);
	ll ans = 0,dp = 0;
	for(int i = 0;i<n;i++){
		ll val;
		val = (ll)getchar();
		val -= 'A';
		val -= 13;
		ans = max(ans,dp+val);
		dp = max(0LL,dp+val);
	}
	printf("%lld",ans);
}

