#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 5e5+10;
ll arr[mxn];
ll dp[mxn];
ll re[mxn];
ll n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	deque<pll> dq;//pos,sum
	dq.push_back(make_pair(n+1,0));
	for(int i = n;i>=1;i--){
		while(arr[dq.back().fs]>arr[i])dq.pop_back();
		ll sum = dq.back().sc;
		sum += (dq.back().fs-i)*arr[i];
		dq.push_back(make_pair(i,sum));
		dp[i] = sum;
	}
	pll ans = {dp[1],0};
	dq.clear();
	dq.push_back(make_pair(0,0));
	for(int i = 1;i<=n;i++){
		while(arr[dq.back().fs]>arr[i])dq.pop_back();
		ll sum = dq.back().sc;
		sum += (i-dq.back().fs)*arr[i];
		ans = max(ans,make_pair(dp[i+1]+sum,1LL*i));
		dq.push_back(make_pair(i,sum));
	}
	re[ans.sc] = arr[ans.sc];
	for(int i = ans.sc-1;i>=1;i--){
		arr[i] = min(arr[i],arr[i+1]);
		re[i] = arr[i];
	}
	re[ans.sc+1] = arr[ans.sc+1];
	for(int i = ans.sc+2;i<=n;i++){
		arr[i] = min(arr[i],arr[i-1]);
		re[i] = arr[i];
	}
	for(int i = 1;i<=n;i++)cout<<re[i]<<' ';
}
