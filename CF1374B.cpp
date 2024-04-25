#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll n;
	cin>>n;
	ll c2 = 0,c3 = 0,rest = 0;
	while(!(n&1)){
		n>>=1;
		c2++;
	}
	while(n%3 == 0){
		n/=3;
		c3++;
	}
	if(n != 1){
		cout<<"-1\n";
		return;
	}
	if(c3>=c2)cout<<c3+c3-c2<<'\n';
	else cout<<"-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
