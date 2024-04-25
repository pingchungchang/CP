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
	int n,k;
	cin>>n>>k;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int tmp;
		cin>>tmp;
		ans = max(ans,tmp|k);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

