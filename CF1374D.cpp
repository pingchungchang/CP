#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	map<int,int> mp;
	for(int i = 0;i<n;i++){
		int c;
		cin>>c;
		mp[c%k]++;
	}
	pii big = {0,0};
	for(auto &i:mp){
		if(i.fs == 0)continue;
		big = max(big,make_pair(i.sc,k-i.fs));
	}
	if(big.fs == 0&&big.sc == 0)cout<<"0\n";
	else cout<<1LL*k*(big.fs-1)+big.sc+1<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
