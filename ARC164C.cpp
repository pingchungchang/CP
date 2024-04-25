#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn = 2e5+10;
int n;
pii arr[mxn];
int tp[mxn];

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i].fs>>arr[i].sc;
	for(int i = 1;i<=n;i++){
		if(arr[i].fs == arr[i].sc){
			ll ans = 0;
			for(int j = 1;j<=n;j++)ans += max(arr[j].fs,arr[j].sc);
			cout<<ans;
			return 0;
		}
		if(arr[i].fs>arr[i].sc)tp[i] = 1;
		else tp[i] = 0;
	}
	int s =0;
	for(int i = 1;i<=n;i++)s += tp[i];
	if(s%2 == 0){
		ll ans = 0;
		for(int i = 1;i<=n;i++)ans += max(arr[i].fs,arr[i].sc);
		cout<<ans;
		return 0;
	}
	int big = 1e15;
	for(int i = 1;i<=n;i++){
		big = min(big,abs(arr[i].fs-arr[i].sc));
	}
	ll ans = 0;
	for(int i = 1;i<=n;i++)ans += max(arr[i].fs,arr[i].sc);
	cout<<ans-big;
}
