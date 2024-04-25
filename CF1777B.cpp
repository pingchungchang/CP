#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9+7;

void solve(){
	int n;
	cin>>n;
	ll tmp = 1;
	for(int i= 2;i<=n;i++)tmp = tmp*i%mod;
	cout<<tmp*n%mod*(n-1)%mod<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
