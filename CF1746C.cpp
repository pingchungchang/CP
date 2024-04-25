#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for(int i = 1;i<n;i++){
		pq.push(make_pair(-arr[i]+arr[i-1],i+1));
	}
	int ans[n] = {};
	for(int i = 1;i<n;i++){
		ans[i] = pq.top().sc;
		pq.pop();
	}
	ans[0] = 1;
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
