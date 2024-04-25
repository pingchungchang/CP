#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int high = 1;
	n--;
	while(high<=n)high<<=1;
	high>>=1;
	for(int i = n;i>=high;i--)cout<<i<<' ';
	cout<<0<<' ';
	for(int i = high-1;i>0;i--)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
