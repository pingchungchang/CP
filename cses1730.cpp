#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int now = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		now ^= k;
	}
	if(now == 0)cout<<"second\n";
	else cout<<"first\n";
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;++i)solve();
}
