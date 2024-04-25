#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<string,int> mp;
	for(int i = 1;i<n;i++){
		mp[s.substr(i-1,2)]++;
	}
	pair<int,string> ans = {0,"ZZ"};
	for(auto &i:mp){
		ans = max(ans,make_pair(i.sc,i.fs));
	}
	cout<<ans.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
