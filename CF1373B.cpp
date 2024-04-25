#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	pii cnt = {0,0};
	for(auto &i:s)if(i == '0')cnt.fs++;else cnt.sc++;
	int ans = min(cnt.fs,cnt.sc);
	if(ans&1)cout<<"DA\n";
	else cout<<"NET\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
