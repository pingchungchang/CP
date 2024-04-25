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
	int arr[n+2];
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	int pref[n+2] = {};
	for(int i = 2;i<n;i++)if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])pref[i] = 1;
	for(int i = 1;i<=n+1;i++)pref[i] += pref[i-1];
	pii ans = {-1,-1};
	for(int i = 1;i+k-1<=n;i++){
		ans = max(ans,make_pair(pref[i+k-2]-pref[i],-i));
	}
	cout<<ans.fs+1<<' '<<-ans.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
