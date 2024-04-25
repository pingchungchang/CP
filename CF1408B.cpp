#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,k;
	cin>>n>>k;
	bool same = false;
	int arr[n];
	for(auto &i:arr)cin>>i;
	int cnt = 1;
	for(int i = 1;i<n;i++)if(arr[i] != arr[i-1])cnt++;
	if(cnt<=k){
		cout<<"1\n";
		return;
	}
	int ans = 0;
	ans++;cnt -= k;
	k--;
	if(!k){
		cout<<"-1\n";
		return;
	}
	cout<<ans+(cnt+k-1)/k<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
