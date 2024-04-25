#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	ll n,m;
	cin>>n>>m;
	if((max(n,m)-min(n,m))&1)cout<<"-1\n";
	else if((n+m)/2 != 0&&n != m){
		cout<<2<<'\n';
	}
	else if(n == 0)cout<<"0\n";
	else cout<<"1\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

