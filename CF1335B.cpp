#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	string ans;
	for(int i = 0;i<b;i++){
		ans += 'a'+i;
	}
	while(ans.size()<a)ans += ans.back();
	while(ans.size()<n)ans += ans;
	cout<<ans.substr(0,n)<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
