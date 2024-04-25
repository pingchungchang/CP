#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e4+10;
ll dif[mxn],dp[mxn],fam[mxn],tp[mxn],arr[mxn],good[mxn];
int n,m;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=m;i++)cin>>fam[i];
	for(int i = 0;i<n;i++){
		cin>>good[i]>>dif[i]>>tp[i];
		arr[i] = i;
	}
	sort(arr,arr+n,[](int a,int b){return dif[a]<dif[b];});
	for(int i = 0;i<n;i++){
		int now = arr[i];
		ll big = 0;
		for(int j = 0;j<=m;j++){
			if(!j||j != tp[now])big = max(big,dp[j]+good[now]);
			else big = max(big,dp[j]+good[now]-fam[tp[now]]);
		}
		dp[tp[now]] = max(dp[tp[now]],big);
	}
	cout<<*max_element(dp,dp+mxn);
}
