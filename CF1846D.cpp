#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define ld long double


void solve(){
	ll n,d,h;
	cin>>n>>d>>h;
	ll arr[n];
	for(auto &i:arr)cin>>i;
	ld ans = 0;
	for(int i = 0;i<n-1;i++){
		if(arr[i+1]-arr[i]>=h){
			ans += d*h/2.0;
		}
		else{
			ld hh = arr[i+1]-arr[i];
			ld dd = d*(h-hh)/h;
			ans += (dd+d)*hh/2.0;
		}
	}
	ans += d*h/2.0;
	cout<<fixed<<setprecision(10)<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
