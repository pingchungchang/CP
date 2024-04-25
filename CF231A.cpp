#include <bits/stdc++.h>
using namespace std;

int ans = 0;
void solve(){
	int s = 0;
	for(int i = 0;i<3;i++){
		int k;
		cin>>k;
		s+= k;
	}
	if(s>=2)ans++;
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
	cout<<ans<<'\n';
}
