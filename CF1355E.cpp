#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
ll A,R,M,n;
ll arr[mxn],pref[mxn];

ll calc(ll k){
	ll pos = 0,neg = 0;
	for(int i = 1;i<=n;i++){
		if(k>arr[i])pos+=k-arr[i];
		else neg += arr[i]-k;
	}
	ll re = 0;
	re += min(pos,neg)*min(M,A+R);
	if(pos>neg)re += (pos-neg)*A;
	else re += (neg-pos)*R;
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>A>>R>>M;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)pref[i] = arr[i]+pref[i-1];
	sort(arr,arr+n);
	ll ans = 5e18;
	ll l = 0,r = 1e9;
	while(r-l>1){
		ll mid = (l+r)>>1;
		if(calc(mid)>calc(mid+1))l = mid+1;
		else r = mid;
	}
	cout<<min(calc(l),calc(r));
}
