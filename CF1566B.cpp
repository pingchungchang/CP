#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int o = 0,z = 0;
	string ss;
	for(auto &i:s){
		if(ss.empty()||ss.back() != i)ss+=i;
	}
	for(auto &i:ss){
		if(i == '1')o++;
		else z++;
	}
	if(!z)cout<<0<<'\n';
	else cout<<min(2,z)<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
