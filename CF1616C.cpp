#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define int ll
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i];
	int ans = n-1;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			int tmp = n-1;
			ld now = arr[i];
			ld diff = (ld)(arr[j]-arr[i])/(j-i);
			for(int k = i+1;k<n;k++){
				now += diff;
				if(abs(arr[k]-now)<=1e-6)tmp--;
			}
//			cout<<i<<' '<<j<<' '<<tmp<<'\n';
			ans = min(ans,tmp);
		}
	}
	cout<<ans<<'\n';
	return;
}
main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

