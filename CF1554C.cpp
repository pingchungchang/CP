#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll a,b;
	cin>>a>>b;
	b++;
	ll ans = 0;
	for(int i = 30;i>=0;i--){
		if((a&(1<<i)) == (b&(1<<i)))continue;
		if(a&(1<<i))break;
		ans |= 1<<i;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
