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
	int n = s.size();
	vector<int> ans;
	for(int i = 0;i+5<=n;i++){
		if(s.substr(i,5) == "twone"){
			ans.push_back(i+2);
			s[i+2] = '#';
		}
	}
	for(int i = 0;i+3<=n;i++){
		if(s.substr(i,3) == "one"){
			ans.push_back(i+1);
			s[i+1] = '#';
		}
		else if(s.substr(i,3) == "two"){
			ans.push_back(i+1);
			s[i+1] = '#';
		}
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i+1<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
