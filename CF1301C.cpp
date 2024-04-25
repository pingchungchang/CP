#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	ll n,o,z;
	cin>>n>>o;z = n-o;
	if(!o){
		cout<<"0\n";
		return;
	}
	if(o>=z-1){
		cout<<n*(n+1)/2-z<<'\n';
		return;
	}
	//k -> k*(o+1) = z -> k = z/(o+1)
	ll C = (z)/(o+1);
	ll R = z%(o+1);
	cout<<n*(n+1)/2-R*(C+2)*(C+1)/2-C*(C+1)/2*(o+1-R)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
