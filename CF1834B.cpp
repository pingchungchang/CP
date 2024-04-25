#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string a,b;
	cin>>a>>b;
	while(a.size() != b.size())a = "0"+a;
	int p = 0;
	for(;p<b.size()&&a[p] == b[p];p++);
	int ans = 0;
	for(int i = p+1;i<a.size();i++)ans += 9;
	if(p != a.size())ans += abs(b[p]-a[p]);
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
