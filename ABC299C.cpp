#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	ll o = n+2,no = n+2;
	ll ans = -1;
	for(int i = 0;i<n;i++){
		if(s[i] == 'o')no = min(no,i),ans = max(ans,i-o);
		else{
			ans = max(ans,i-no);
			o = i;
			no = n+2;
		}
	}
	cout<<ans;
}
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
