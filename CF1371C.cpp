#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll a,b,n,m;
	cin>>a>>b>>n>>m;
	if(a>b)b -= m;
	else a -= m;
	if(a<0||b<0){
		cout<<"NO\n";
		return;
	}
	if(a+b<n)cout<<"NO\n";
	else cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
