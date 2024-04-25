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
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	int ans = 0;
	for(int i = 1;i<n;i++){
		ans += min(arr[i]/arr[0]-1,(arr[i]+arr[0]*2-2)/(arr[0]*2-1)-1);
	}
	cout<<ans<<'\n';
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

