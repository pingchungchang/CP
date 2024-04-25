#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,m,k,H;
	cin>>n>>m>>k>>H;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		int d = abs(tmp-H);
		if(d != 0&&d%k == 0 && d/k<m)ans++;
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
