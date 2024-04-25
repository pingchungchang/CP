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
	vector<int> v[2];
	int c = 0;
	int ans[n] = {};
	for(int i = 0;i<n;i++){
		int k = s[i]-'0';
		if(!v[k^1].empty()){
			ans[i] = v[k^1].back();
			v[k].push_back(v[k^1].back());
			v[k^1].pop_back();
		}
		else{
			v[k].push_back(++c);
			ans[i] = c;
		}
	}
	cout<<c<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
