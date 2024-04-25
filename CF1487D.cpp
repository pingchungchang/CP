#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	cout<<((int)sqrt(2*n-1)+1)/2 -1<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
