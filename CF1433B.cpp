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
	int n;
	cin>>n;
	vector<int> v;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(v.empty()&&k == 0)continue;
		else if(k == 0)v.push_back(k);
		else if(v.empty())v.push_back(k);
		else if(v.back() == 1)continue;
		else v.push_back(k);
	}
//	for(auto i:v)cout<<i<<' ';cout<<'\n';
	while(!v.empty()&&v.back() != 1)v.pop_back();
	int ans = 0;
	for(auto &i:v)if(i == 0)ans++;
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

