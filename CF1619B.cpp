#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> v;
void solve(){
	ll n;
	cin>>n;
	cout<<upper_bound(v.begin(),v.end(),n)-v.begin()<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(ll i = 1;i*i<=1e9;i++){
		v.push_back(i*i);
		if(i*i*i<=1e9)v.push_back(i*i*i);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
