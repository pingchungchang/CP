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
	ll n;
	cin>>n;
	vector<int> v(n+2,0);
	for(int i = 1;i<=n;i++){
		cin>>v[i];
	}
	string pre = string(200,'a');
	cout<<pre<<'\n';
	for(int i = 1;i<=n;i++){
		if(pre[v[i]] == 'a')pre[v[i]] = 'b';
		else pre[v[i]] = 'a';
		cout<<pre<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

