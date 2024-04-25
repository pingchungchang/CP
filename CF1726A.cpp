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
void solve(){
	int n;
	cin>>n;
	int ans = 0;
	int arr[n];
	for(auto &i:arr)cin>>i;
	for(int i = 0;i<n;i++)ans = max(ans,arr[i]-arr[(i+1)%n]);
	if(n>1)ans = max(*max_element(arr+1,arr+n)-arr[0],ans);
	if(n>1)ans = max(arr[n-1]-*min_element(arr,arr+n-1),ans);
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

