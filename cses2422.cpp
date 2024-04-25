#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


ll n;
ll m;

inline bool f(ll tar){
	ll cnt = 0;
	for(int i = 1;i<=n;i++){
		cnt += min(n,tar/i);
	}
	return cnt>=m;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	m = n*n/2+1;
	ll l = 0,r = 1e12;
	while(l != r){
		ll mid = (l+r)>>1;
		if(f(mid))r = mid;
		else l = mid+1;
	}
	cout<<l;
}
