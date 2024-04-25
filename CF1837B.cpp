#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	char p = '#';
	int cnt = 0;
	int ans = 0;
	for(auto &i:s){
		if(i == p)cnt++;
		else cnt = 1;
		p = i;
		ans = max(ans,cnt);
	}
	cout<<ans+1<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
