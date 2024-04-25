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
	int n;
	cin>>n;
	int a,va,c,vc,b;
	cin>>a>>va>>c>>vc>>b;
	int r = min(b-a,vc-va)+va;
	int l = vc-min(c-b,vc-va);
	cout<<(l+r)/2<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

