#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 3e5+10;

ll arr[mxn],brr[mxn];
int n,m;

void solve(){
	cin>>n>>m;
	for(int i = 0;i<n;i++)cin>>arr[i],arr[i]--;
	for(int i = 0;i<m;i++)cin>>brr[i];
	sort(arr,arr+n);
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	int pt = 0;
	ll ans = 0;
	for(int i = 0;i<n;i++){
		while(pt<=arr[i]){
			pq.push(brr[pt]);
			pt++;
		}
		ans += pq.top();
		ll tmp = pq.top();
		pq.pop();
		pq.push(brr[arr[i]]);
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
