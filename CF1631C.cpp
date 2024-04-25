#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
	ll n,k;
	cin>>n>>k;
	if(k == n-1){
		if(n == 4){
			cout<<-1<<'\n';
			return;
		}
		cout<<n-2<<' '<<n-1<<'\n';
		cout<<1<<' '<<3<<'\n';
		cout<<0<<' '<<n-1-3<<'\n';
		for(ll i = 0;i<n;i++){
			if(i == 0||i == n-2||i == n-1||i == n-1-3||i == 3||i==1)continue;
			if(i<n-1-i)cout<<i<<' '<<n-1-i<<'\n';
		}
		return;
	}
	if(k != 0)cout<<0<<' '<<n-1-k<<'\n';
	if(k != 0)cout<<k<<' '<<n-1<<'\n';
	if(k == 0)cout<<0<<' '<<n-1<<'\n';
	for(ll i = 0;i<n;i++){
		if(i != 0&&i != n-1-k&&i != k&&i != n-1){
			if(i<n-1-i){
				cout<<i<<' '<<n-i-1<<'\n';
			}
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i =0;i<t;i++)solve();
}
