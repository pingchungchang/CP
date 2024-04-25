#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
ll dp[mxn];
ll arr[mxn],brr[mxn];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>brr[i];
	for(int i = n;i>=1;i--){
		pll sum = make_pair(0,0);
		for(int j = i;j<=n;j+=i){
			dp[i] -= dp[j];
			dp[i] += sum.fs*brr[j]+sum.sc*arr[j]+arr[j]*brr[j];
			sum.fs += arr[j];
			sum.sc += brr[j];
		}
	}
	for(int i = 1;i<=n;i++)cout<<dp[i]<<' ';
	return 0;
}
