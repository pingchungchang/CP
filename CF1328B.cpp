#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll a,b;
	cin>>a>>b;
	string ans(a,'a');
	ll p1 = 0,p2 = 1;
	while(p2<a&&b>p2){
		b-= p2;
		p2++;
	}
	b--;
	while(b--)p1++;
	ans[p2] = ans[p1] = 'b';
	reverse(ans.begin(),ans.end());
	//cout<<p1<<' '<<p2<<'\n';
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
