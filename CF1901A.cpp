#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 110;
int arr[mxn];
int n,x;

void solve(){
	for(int i = 0;i<=x;i++)arr[i] = 0;
	cin>>n>>x;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	int ans = arr[0];
	for(int i = 1;i<n;i++)ans = max(ans,arr[i]-arr[i-1]);
	ans = max(ans,(x-arr[n-1])*2);
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
