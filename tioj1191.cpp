#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

string s;

void solve(){
	ll ans = 0;
	ll p = 1;
	while(!s.empty()){
		ll tmp = s.back()-'0';
		s.pop_back();
		if(tmp>=6)tmp--;
		ans += tmp*p;
		p*=9;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>s&&s != "0")solve();
}
