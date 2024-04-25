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

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> ans;
	for(int i = (m+1);i<=n;i++){
		ans.push_back(i);
	}
	int total = 0;
	for(int i = (m+1)/2;i<m;i++){
		ans.push_back(i);
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans)cout<<i<<' ';
	cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

