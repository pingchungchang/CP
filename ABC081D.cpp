#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
	ll n;
	cin>>n;
	ll v[n];
	for(ll i = 0;i<n;i++)cin>>v[i];
	pll b = make_pair(INT_MIN,0),s = make_pair(INT_MAX,INT_MAX);
	for(ll i = 0;i<n;i++){
		b = max(b,make_pair(v[i],i));
		s = min(s,make_pair(v[i],i));
	}
	vector<pll> ans;
	if(abs(b.fs)>abs(s.fs)){
		for(ll i = 0;i<n;i++){
			ans.push_back(make_pair(b.sc,i));
			v[i] += b.fs;
		}
		for(ll i = 1;i<n;i++){
			ans.push_back(make_pair(i-1,i));
		}
	}
	else{
		for(ll i = 0;i<n;i++)ans.push_back(make_pair(s.sc,i));
		for(ll i = n-2;i>=0;i--){
			ans.push_back(make_pair(i+1,i));
		}
	}
	cout<<ans.size()<<"\n";
	for(auto i:ans)cout<<i.fs+1<<' '<<i.sc+1<<'\n';
	return 0;
}

