#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,x;
	cin>>n>>x;
	if(n<=2){
		cout<<"1\n";
		return;
	}
	n -= 2;
	int ans = 2;
	while(n>x){
		ans++;
		n -= x;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
