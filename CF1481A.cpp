#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	pll tar;
	cin>>tar.fs>>tar.sc;
	pll x = {0,0},y = x;
	string s;
	cin>>s;
	for(auto &i:s){
		if(i == 'U')y.sc++;
		else if(i == 'D')y.fs--;
		else if(i == 'L')x.fs--;
		else x.sc++;
	}
	if(x.fs<=tar.fs&&tar.fs<=x.sc&&y.fs<=tar.sc&&tar.sc<=y.sc)cout<<"YES\n";
	else cout<<"NO\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
