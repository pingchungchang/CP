#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n,g,b;
	cin>>n>>g>>b;
	if(g>=b){
		cout<<n<<'\n';
		return;
	}
	ll c = (n+1)/2;
	if(c%g == 0){
		ll tans = (c/g-1)*(g+b)+g;
		cout<<max(tans,n)<<'\n';
	}
	else{
		ll tans = (c/g)*(g+b)+c%g;
		cout<<max(tans,n)<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
