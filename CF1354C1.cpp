#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld PI = acos(-1);

void solve(){
	int n;
	cin>>n;
	ld theta = PI/n/2;
	cout<<fixed<<setprecision(20)<<1/tan(theta)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
