#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
	ll a,b;
	cin>>a>>b;
	swap(a,b);
	cout<<(b-a)*2<<'\n';
	for(ll i = a;i<=b;i++)cout<<i<<' ';
	for(ll i = b-1;i>a;i--)cout<<i<<' ';
	cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
