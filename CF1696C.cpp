#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<pll> va,vb;
	vector<ll> a(n);
	for(int i = 0;i<n;i++)cin>>a[i];
	cin>>n;
	vector<ll> b(n);
	for(int i = 0;i<n;i++)cin>>b[i];
	for(auto i:a){
		ll cnt = 1;
		while(i %m == 0){
			i /=m;
			cnt *= m;
		}
		if(va.empty()||va.back().fs != i)va.push_back(make_pair(i,cnt));
		else{
			va.back().sc += cnt;
		}
	}
	for(auto i:b){
		ll cnt = 1;
		while(i %m == 0){
			i /=m;
			cnt *= m;
		}
		if(vb.empty()||vb.back().fs != i)vb.push_back(make_pair(i,cnt));
		else vb.back().sc+= cnt;
	}
	if(va.size()!= vb.size()){
		cout<<"NO\n";
		return;
	}
	for(int i = 0;i<va.size();i++){
		if(va[i].fs != vb[i].fs||va[i].sc != vb[i].sc){
			cout<<"NO\n";
			return;
		}		
	}
	cout<<"YES\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

