#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll

const int mxn = 2e5+10;
ll arr[mxn];
int n;
priority_queue<pll,vector<pll>,greater<pll>> pq;
ll c;

void solve(){
	while(!pq.empty())pq.pop();
	cin>>n>>c;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	if(n == 1){
		cout<<"YES\n";
		return;
	}
	for(int i = 2;i<=n;i++){
		pq.push(make_pair(c*i-arr[i],arr[i]));
	}
	while(!pq.empty()){
		if(arr[1]>=pq.top().fs){
			arr[1] += pq.top().sc;
		}
		else{
			cout<<"NO\n";
			return;
		}
		pq.pop();
	}
	cout<<"YES\n";
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
