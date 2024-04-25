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
	map<int,pii> mp;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		mp[k].fs++;
		mp[k].sc = i;
	}
	for(auto &i:mp){
		if(i.sc.fs == 1){
			cout<<i.sc.sc<<'\n';
			return;
		}
	}
	cout<<"-1\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
