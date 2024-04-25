#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	bool done = 0;
	if((n&1)==0)done = true;
	for(int i = 1;i<n;i++){
		if(v[i]<=v[i-1])done = true;
	}
	if(done)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int i = 0;i<t;++i)solve();
}
