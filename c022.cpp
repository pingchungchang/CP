#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

void solve(){
	int s,e;
	cin>>s>>e;
	s--;
	if(s%2 == 0)s--;
	s = max(0,s);
	if(e%2 == 0)e--;
	cout<<((e+1)>>1)*((e+1)>>1)-((s+1)>>1)*((s+1)>>1)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(int i = 1;i<=t;i++){
		cout<<"Case "<<i<<": ";
		solve();
	}
}
