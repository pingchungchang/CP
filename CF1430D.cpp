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
	string s;
	cin>>s;
	vector<pii> v;
	for(auto &i:s){
		if(v.empty()||v.back().sc != i-'0')v.push_back({1,i-'0'});
		else v.back().fs++;
	}
	int now = 0,ans = 0,p = 0;
	n = v.size();
	bool flag = false;
	while(now < n){
		while(!flag&&p<n&&v[p].fs == 1)p++;
		if(p == n)flag = true;
		if(flag){
			now++;
		}
		else v[p].fs--;
		now++;
		ans++;
		if(p<now)p = now;
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

