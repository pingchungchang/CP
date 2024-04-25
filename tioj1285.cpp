#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


ll a,b;
void solve(){
	ll ans = 0;
	while(b != 0){
		if(a<b)swap(a,b);
		ans += a/b;
		a %= b;
		swap(a,b);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>a>>b)solve();
}
