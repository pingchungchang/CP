#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll g(ll x){
	return x%3 == 0?1+g(x/3):0LL;
}

ll f(ll x){
	return x<=0?0LL:g(x)+f(x-1);
}

ll calc(ll k){
	ll now = 3;
	ll ans = 0;
	while(now<=k){
		ans += k/now;
		now *= 3;
	}
	return ans;
}

bool flag = false;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	while(cin>>n){
		if(flag)cout<<'\n';
		cout<<calc(n);
		flag = true;
	}
	return 0;
}
