#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int total = 0;
	while(n--){
		int k;
		cin>>k;
		total ^= k%4;
	}
	cout<<(total?"first":"second")<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}