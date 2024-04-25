#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	pll a,b;
	cin>>a.fs>>a.sc>>b.fs>>b.sc;
	if(a.fs>a.sc)swap(a.fs,a.sc);
	b = {b.fs-b.sc,b.fs+b.sc};
	cout<<a.sc-a.fs-max(0LL,min(a.sc,b.sc)-max(a.fs,b.fs))<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
