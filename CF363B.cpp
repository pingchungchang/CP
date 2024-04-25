#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n,k;
	cin>>n>>k;
	ll arr[n+1];arr[0] = 0;
	for(int i =1 ;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)arr[i] += arr[i-1];
	pll ans = make_pair(INT_MAX,INT_MAX);
	for(int i = 1;i<=n-k+1;i++){
		ll sum = arr[i+k-1]-arr[i-1];
		if(sum<=ans.sc){
			ans = make_pair(i,arr[i+k-1]-arr[i-1]);
		}
	}
	cout<<ans.fs;
}

