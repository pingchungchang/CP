#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

ll dt = 1e9;

inline ll f(ll s,ll t){
	if(s%10 == 0)return s;
	if(!t)return s;
	if(s%10 == 5){
		return s+5;
	}
	s += s%10;
	t--;
	int p = 0;
	int arr[] = {2,4,8,6,2,4,8,6};
	for(p = 0;p<5;p++){
		if(s%10 == arr[p])break;
	}
	s += t/4*20;
	t %= 4;
	for(int i = 0;i<t;i++)s += arr[p+i];
	return s;
}

void solve(){
	ll k,s;
	cin>>s>>k;
	ll ans = s*k;
	s += s%10;
	k--;
	ans = max(ans,s*k);
	if(s%10 == 0){
		cout<<ans<<'\n';
		return;
	}
	vector<ll> v = {s%10};
	for(int i = 0;i<3;i++)v.push_back(v.back()*2%10);
	for(int i = 0;i<4;i++){
		if(k<i+1)break;
		ll l = 0,r = k/4;
		if(r*4+i+1>k)r--;
		auto calc = [&](ll x){
			if(x<0||x*4+i+1>k)return -1LL;
			ll ss = 0;
			for(int j = 0;j<=i;j++)ss += v[j];
			return (k-x*4-i-1)*(s+x*20+ss);
		};
		while(r-l>1){
			ll mid = (l+r)>>1;
			//cout<<l<<' '<<r<<' '<<calc(mid-1)<<' '<<calc(mid)<<endl;
			if(calc(mid)>calc(mid+1))r = mid;
			else l = mid;
		}
		ans = max({ans,calc(l),calc(r)});
	}
	cout<<ans<<'\n';
	return;
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
