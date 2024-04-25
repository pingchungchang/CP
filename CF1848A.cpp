#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	pii p;
	cin>>p.fs>>p.sc;
	pii arr[k];
	for(auto &i:arr)cin>>i.fs>>i.sc;
	for(auto &i:arr){
		if((abs(i.fs-p.fs)+abs(i.sc-p.sc))%2 == 0){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
