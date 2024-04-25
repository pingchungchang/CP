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
	ll n;
	cin>>n;
	vector<ll> v(n,0);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	ll ans = INT_MAX;
	for(int i = 0;i<n-1;i++){
		ll a= v[i],b = v[i+1];
		if(a>b)swap(a,b);
		if(a>=(b-a)){
			ans  = min(ans,(a+b+2)/3);
		}
		else{
			ans = min(ans,(b+1)/2);
		}
	}	
	for(int i = 0;i<n-2;i++){
		ll a = v[i],b = v[i+2];
		if(a>b)swap(a,b);
		b -=a;
		ans = min(ans,a+(b+1)/2);
	}
	sort(_all(v));
	ans = min(ans,(v[0]+1)/2+(v[1]+1)/2);
	cout<<ans<<'\n';
}

