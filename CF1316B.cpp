#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	string s;
	cin>>n>>s;
	pair<string,int> ans;
	ans = {s,1};
	reverse(s.begin(),s.end());
	ans = min(ans,make_pair(s,n));
	reverse(s.begin(),s.end());
	for(int i = 1;i<n-1;i++){
		string tmp = s.substr(i,n-i);
		string ts = s.substr(0,i);
		if((n-i)&1)reverse(ts.begin(),ts.end());
		tmp += ts;
		ans = min(ans,make_pair(tmp,i+1));
	}
	cout<<ans.fs<<'\n'<<ans.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
