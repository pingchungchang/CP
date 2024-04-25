#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3e5+10;
ll arr[mxn];

void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i],arr[i] += arr[i-1];
	deque<ll> dq = {0};
	for(int i = 1;i<=n;i++){
		while(!dq.empty()&&arr[dq.back()]>=arr[i])dq.pop_back();
		dq.push_back(i);
	}
	pll ans = {arr[n],-(ll)1e18};
	for(int i = 0;i<=n;i++){
		while(!dq.empty()&&dq.front()<i)dq.pop_front();
		ans = max(ans,make_pair(arr[n]+arr[i]-arr[dq.front()],arr[i]));
	}
	cout<<ans.sc<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
