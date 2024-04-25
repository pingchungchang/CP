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
	int x;
	cin>>x;
	string ans(s.size(),'1');
	for(int i = 0;i<s.size();i++){
		if(s[i] == '0'){
			if(i+x<s.size())ans[i+x] = '0';
			if(i-x>=0)ans[i-x] = '0';
		}
	}
	for(int i = 0;i<s.size();i++){
		char c = '0';
		if(i+x<ans.size()&&ans[i+x] == '1')c = '1';
		if(i-x>=0&&ans[i-x] == '1')c = '1';
		if(c != s[i]){
			cout<<"-1\n";
			return;
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
