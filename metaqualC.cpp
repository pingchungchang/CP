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
vector<string> ans;
int n;
string now;
void dfs(){
	if(ans.size()>=n-1)return;
	if(now.size() == 10){
		ans.push_back(now);
		return;
	}
	now += '.';
	dfs();
	now.pop_back();
	now += '-';
	dfs();
	now.pop_back();
}
void solve(){
	ans.clear();
	cin>>n;
	string s;
	cin>>s;
	if(s[0] == '.')now = "-";
	else now = ".";
	dfs();
	for(int i = 0;i<n-1;i++)cout<<ans[i]<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int asd = 1;asd<=t;asd++){
		cout<<"Case #"<<asd<<": \n";
		solve();
	}
}

