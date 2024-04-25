#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	ll x,y,a,b;
	cin>>x>>y>>a>>b;
	ll d =y-x;
	if(d%(a+b) == 0){
		cout<<d/(a+b)<<'\n';
	}
	else cout<<"-1\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
