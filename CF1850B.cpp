#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	pii ans = {-1,-1};
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		if(a<=10)ans = max(ans,make_pair(b,i));
	}
	cout<<ans.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
