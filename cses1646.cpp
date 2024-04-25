#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	vector<ll> v(1+n,0);
	for(int i = 1;i<=n;i++){
		cin>>v[i];
		v[i]+= v[i-1];
	}
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		cout<<v[b]-v[a-1]<<'\n';
	}
}
