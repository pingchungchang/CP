#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	int ans = a+b;
	for(int i= 1;i<=n;i++){
		int k;
		cin>>k;
		if(k == ans)cout<<i<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
