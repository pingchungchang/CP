#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 2e7+10;
ll arr[mxn];
ll sum = 0;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		sum += arr[i];
	}

	ll tsum = 0;
	for(int i = 1;i<=n;i++)tsum += arr[i]*(i-1);
	for(int i = 0;i<n;i++){
		tsum -= arr[i]*(i-1);
		tsum -= arr[n+1-i]*(n-i);
		tsum += arr[i]*(n-i);
		tsum += arr[n+1-i]*(i-1);
		if(tsum%sum == 0){
			cout<<i<<' '<<tsum/sum<<'\n';
			return 0;
		}
	}
	assert(false);
}
