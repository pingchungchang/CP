#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int a,b;
	cin>>a>>b;
	int ans = 1e9;
	ans = min(ans,max(a,b*2)*max(a,b*2));
	ans = min(ans,max(a*2,b)*max(a*2,b));
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
