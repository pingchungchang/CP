#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll A,B;
	cin>>A>>B;
	ll bc = 9;
	ll ans = 0;
	while(bc<=B){
		ans++;
		bc = bc*10+9;
	}
	cout<<ans*A<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
