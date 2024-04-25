#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 1e5+10;
int arr[mxn];

void solve(){
	ll n,s;
	cin>>n>>s;
	priority_queue<pii> pq;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	ll total = 0;
	pii ans = {0,0};
	for(int i = 1;i<=n;i++){
		pq.push({arr[i],i});
		total += arr[i];
		if(total<=s)ans = max(ans,make_pair(i,0));
		else if(total-pq.top().fs<=s)ans = max(ans,make_pair(i-1,pq.top().sc));
	}
	cout<<ans.sc<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
