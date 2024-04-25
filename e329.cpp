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
ll small = INT_MAX;
deque<pll> dq;
int main(){
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int p = 0;
	ll total = 0;
	ll ans = 0;
	dq.push_back({0,INT_MAX});
	for(int i = 0;i<4e6+10;i++){
		while(dq.front()<=i-m){
			small = min(small,dq.front().sc);
		}
	}
}
//dp[i] = min dp[j] +sum[i]-sum[j]
