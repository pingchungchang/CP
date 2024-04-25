#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int ans = 0;
	ll total = 0;
	ll pre = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		total += abs(k);
		if(k<0){
			if(!pre)ans++;
			pre = 1;
		}
		else if(k>0)pre = 0;
	}
	cout<<total<<' '<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
