#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int cnt = 0;
	for(int i =0;i<n;i++){
		if(a[i] != b[i])cnt++;
	}
	int ans = 1e9;
	if(cnt&1){
		ans = min(ans,cnt*2-1);
	}
	else ans = min(ans,cnt*2);
	reverse(a.begin(),a.end());
	cnt = 0;
	for(int i = 0;i<n;i++)if(a[i] != b[i])cnt++;
	if(cnt&1){
		ans = min(ans,cnt*2);
	}
	else{
		if(cnt == 0)ans = min(ans,2);
		else ans = min(ans,cnt*2-1);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
