#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double


void solve(){
	int n;
	cin>>n;
	vector<vector<int>> v(n+1);
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		v[k].push_back(i);
	}
	vector<int> ans(n+1,0);
//	for(int i = 1;i<=n;i++){
//		cout<<i<<':';
//		for(auto j:v[i])cout<<j<<' ';cout<<'\n';
//	}
	for(int i = 1;i<=n;i++){
		if(v[i].size() == 1)ans[i] = 1;
		else if(v[i].empty())ans[i] = 0;
		else{
			int odd = 0,even = 0;
			for(int j = 0;j<v[i].size();j++){
				if(v[i][j]%2 == 0){
					even = max(even,odd+1);
				}
				else{
					odd = max(odd,even+1);
				}
			}
			ans[i] = max(odd,even);
		}
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

