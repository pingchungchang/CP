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
	if(b == 1){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	cout<<a<<' '<<a*(b*3-1)<<' '<<a*b*3<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
