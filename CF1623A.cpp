#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n,m;
	cin>>n>>m;
	int ra,ca,rb,cb;
	cin>>ra>>ca>>rb>>cb;
	int ans = INT_MAX;
	if(rb<ra){
		ans = min(ans,ra-rb+2*(n-ra));
	}
	else ans = min(ans,rb-ra);
	if(ca>cb){
		ans = min(ans,ca-cb+2*(m-ca));
	}
	else ans = min(ans,cb-ca);
	cout<<ans<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++){
		solve();
	}
} 
