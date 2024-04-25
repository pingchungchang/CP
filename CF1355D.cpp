#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,s;
	cin>>n>>s;
	if(n*2>s){
		cout<<"NO\n";
		return 0;
	}
	ll ans[n];
	for(auto &i:ans)i = 2,s-=2;
	ans[0] += s;
	cout<<"YES\n";
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	cout<<"1\n";
	return 0;
}
