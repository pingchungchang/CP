#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


const int inf = 1e9+10;

void solve(){
	int n;
	cin>>n;
	pii p = {0,inf};
	for(int i = 0;i<n;i++){
		pii tmp;
		cin>>tmp.fs>>tmp.sc;
		p.fs = max(p.fs,tmp.fs);
		p.sc = min(p.sc,tmp.sc);
	}
	cout<<max(0,p.fs-p.sc)<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
