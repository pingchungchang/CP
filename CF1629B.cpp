#include <bits/stdc++.h>
using namespace std;

#define int long long
int l,r,k;
void solve(){
	cin>>l>>r>>k;
	if(l == r&&l != 1)cout<<"YES\n";
	else if(l==r&&l == 1)cout<<"NO\n";
	else if((r-l+1)%2 == 0){
		if((r-l+1)/2<=k)cout<<"YES\n";
		else cout<<"NO\n";
	}
	else if((r-l+1)/2+(r&1)<=k)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}


main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	for(int i =0;i<t;i++){
		solve();
	}
}

