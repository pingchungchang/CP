#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,k;
	cin>>n>>k;
	vector<pair<ll,ll>> v(n);
	for(ll i =0;i<n;i++){
		ll x;
		cin>>x;
		v[i] = make_pair(x,i+1);
	}
	sort(v.begin(),v.end());
	ll p1 =0,p2 = n-1;
	while(p1<p2){
		if(v[p1].first+v[p2].first>k){
			p2--;
		}
		else if(v[p1].first+v[p2].first<k){
			p1++;
		}
		else break;
	}
	if(p2>p1){
		cout<<min(v[p1].second,v[p2].second)<<' '<<max(v[p1].second,v[p2].second);
	}
	else cout<<"IMPOSSIBLE";
}
