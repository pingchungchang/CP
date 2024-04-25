#include <bits/stdc++.h>
using namespace std;

#define ll long long


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll x1;
	ll y1;
	ll x2;
	ll y2;
	cin>>x1>>y1>>x2>>y2;
	int n;
	cin>>n;
	vector<pair<ll,ll>> v(n);
	for(int i = 0;i<n;i++){
		ll a,b;
		cin>>a>>b;
		v[i].first = (a-x1)*(a-x1)+(b-y1)*(b-y1);
		v[i].second = (a-x2)*(a-x2)+(b-y2)*(b-y2);
	}
	sort(v.begin(),v.end());
	for(int i = n-2;i>=0;i--){
		v[i].second = max(v[i].second,v[i+1].second);
	}
	ll ans = v[0].second;
	for(int i = 0;i<n-1;i++){
		ans = min(ans,v[i].first+v[i+1].second);
	}
	ans = min(ans,v[n-1].first);
	cout<<ans;
}
