#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(auto &i:arr)cin>>i;
	queue<pii> q;
	q.push({1,0});
	int ans = 0;
	for(int i = 1;i<n;i++){
		if(arr[i]<arr[i-1])q.pop();
		q.push({arr[i],q.front().sc+1});
	}
	while(!q.empty()){
		ans = max(ans,q.front().sc);
		q.pop();
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
