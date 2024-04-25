#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e5+10;
int dp[mxn];
int arr[mxn];
int pref[mxn];
int n,q;
int ans[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	sort(arr+1,arr+n+1);
	for(int i = 1;i<=n;i++){
		dp[i] = -1e9;
		if(i-arr[i]>=0)dp[i] = max(dp[i],pref[i-arr[i]]+1);
		pref[i] = max(pref[i-1],dp[i]);
	}
	int p = 1;
	for(int i = n;i>=0;i--){
		while(p<=n&&p<=n-i+dp[i]){
			ans[p++] = i;
		}
		while(dp[i]<0&&p<=n-arr[i]+1)ans[p++] = i;
	}
	//for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		cout<<ans[k]<<'\n';
	}
	return 0;
}
