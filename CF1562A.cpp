#include <bits/stdc++.h>
using namespace std;

void solve(){
	int l,r;
	cin>>l>>r;
	if(r/2+1>=l){
		cout<<r%(r/2+1)<<'\n';
	}
	else cout<<r%l<<'\n';
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
