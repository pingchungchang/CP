#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int arr[mxn],brr[mxn];
int n,k;
deque<pll> dq;

void solve(){
	dq.clear();
	cin>>n>>k;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<=n;i++)cin>>brr[i];
	ll ans = 0;
	ll sum = 0;
	for(int i = 1;i<=n;i++){
		if(!dq.empty()&&dq.back().sc%brr[i] != 0)sum = 0,dq.clear();
		dq.push_back({arr[i],brr[i]});
		sum += arr[i];
		while(sum>k){
			sum -= dq.front().fs;
			dq.pop_front();
		}
		ans = max(ans,(ll)dq.size());
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
