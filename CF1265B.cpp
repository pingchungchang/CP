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
	int pos[n+1] = {};
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		pos[k] = i;
	}
	pii p = {pos[1],pos[1]};
	for(int i = 1;i<=n;i++){
		p.fs = min(p.fs,pos[i]);
		p.sc = max(p.sc,pos[i]);
		if(p.sc-p.fs+1 == i){
			cout<<1;
		}
		else cout<<0;
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
