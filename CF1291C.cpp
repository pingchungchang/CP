#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const int mxn = 4040;
int arr[mxn];
int n,m,k;

void solve(){
	cin>>n>>m>>k;
	int ans = 0;
	k = min(k,m-1);
	for(int i = 0;i<n;i++)cin>>arr[i];
	for(int i = 0;i<=k;i++){
		int s = i,e = k-i;
		int small = 1e9;
		for(int l = s;l<m;l++){
			int r = m-1-l;
			if(r<e)continue;
			//cout<<l<<' '<<r<<' '<<s<<' '<<e<<'\n';
			small = min(small,max(arr[l],arr[n-1-r]));
		}
		ans = max(ans,small);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
