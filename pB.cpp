#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
	int n;
	ll k;
	cin>>n>>k;
	ll v[n];
	for(int i = 0;i<n;i++){
		cin>>v[i];
		v[i] -= k;
	}
	ll minsum = 0;
	for(int i = 1;i<n;i++){
		ll tmp = v[i]+v[i-1];
		minsum = min(minsum,tmp);
		v[i] = min(v[i],tmp);
	}
	if(minsum<0)cout<<"No\n";
	else cout<<"Yes\n";
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
