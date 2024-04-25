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
	map<int,vector<int>> mp;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		mp[k].push_back(i);
	}
	for(auto &i:mp){
		if(i.sc.size() == 1){
			cout<<i.sc[0]<<'\n';
			return;
		}
	}
	assert(false);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
