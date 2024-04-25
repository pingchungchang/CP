#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3030;
int pref[mxn][mxn];
int n;

void solve(){
	for(int i = 0;i<=n;i++)for(int j = 0;j<=n;j++)pref[i][j] = 0;
	cin>>n;
	int arr[n+1];
	for(int i = 1;i<=n;i++)cin>>arr[i],pref[arr[i]][i]++;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)pref[i][j] += pref[i][j-1];
	}
	ll ans = 0;
	for(int i = 2;i<n;i++){
		for(int j = i+1;j<n;j++){
			ans += 1LL*pref[arr[j]][i-1]*(pref[arr[i]][n]-pref[arr[i]][j]);
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
