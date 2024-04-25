#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	int ans = n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 1;i<=100;i++){
		int r = -1;
		int tmp = 0;
		for(int j = 0;j<n;j++){
			if(arr[j] != i&&j>r)r = j+k-1,tmp++;
		}
		ans = min(ans,tmp);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
