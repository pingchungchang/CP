#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	string s;
	cin>>s;
	int n = s.size();
	int st = n,ed = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == '1')st = min(st,i),ed = max(ed,i);
	}
	int ans = 0;
	for(int i = st;i<=ed;i++){
		if(s[i] == '0')ans++;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
