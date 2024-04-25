#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

void solve(){
	int n;
	cin>>n;
	ll arr[n+1] = {0LL};
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	ll total = 0;
	ll ans = n;
	for(int r = 1;r<=n;r++){
		total += arr[r];
		ll tmp = 0;
		ll pre = r;
		ll tans = r;
		bool flag = true;
		for(int j = r+1;j<=n;j++){
			tmp += arr[j];
			if(tmp>total){
				flag = false;
				break;
			}
			else if(tmp == total){
				tmp = 0;
				tans = max(tans,1LL*j-pre);
				pre = j;
			}
		}
		if(flag && tmp == 0)ans = min(ans,tans);
//		cout<<r<<' '<<f/lag<<' '<<tans<<endl;
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

