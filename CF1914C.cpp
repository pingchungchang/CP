#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n],brr[n];
	for(auto &i:arr)cin>>i;
	for(auto &i:brr)cin>>i;
	int sum =0,ans = 0;
	int big = 0;
	for(int i = 0;i<n;i++){
		sum += arr[i];
		big = max(big,brr[i]);
		int d = k-i-1;
		if(d<0)break;
		ans = max(ans,sum+big*d);
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
