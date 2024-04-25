#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int pr = n-1;
	int ans = n;
	for(int i = 0;i<n;i++){
		if(i>=pr)break;
		while(pr>i&&INT_MAX-arr[i] < arr[pr])pr--;
		if(pr>i&&arr[i]+arr[pr] == INT_MAX)pr--,ans--;
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
