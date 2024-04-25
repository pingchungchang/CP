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
ll sx,sy,ex,ey,z;
void solve(){
	cin>>sx>>ex>>sy>>ey;
	for(ll i = sy;i<=ey;i++){
		for(ll j = sx;j<=ex;j++){
			if(__gcd(i,__gcd(z,j)) == 1)cout<<"*";
			else cout<<".";
		}
		cout<<'\n';
	}
	cout<<"--\n";
	return;
}
int main(){
	io
	while(cin>>z){
		if(!z)return 0;
		solve();
	}
}

