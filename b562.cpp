#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


string s;
void solve(){
	ll ans = 0;
	ll now = 1;
	int c = 1;
	for(auto it = s.rbegin();it != s.rend();it++){
		if(*it=='1'){
			ans += now*(c?1:-1);
		}
		now<<=1;
		c^=1;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>s)solve();
}
