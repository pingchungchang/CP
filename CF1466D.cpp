#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
int n;
int deg[mxn],arr[mxn];

void solve(){
	for(int i = 0;i<=n;i++)deg[i] = arr[i] = 0;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		deg[a]++;
		deg[b]++;
	}
	priority_queue<ll,vector<ll>,less<ll>> pq;
	for(int i = 1;i<=n;i++){
		deg[i]--;
		while(deg[i]--)pq.push(arr[i]);
	}
	ll sum = 0;
	for(int i = 1;i<=n;i++)sum += arr[i];
	for(int i = 1;i<=n-1;i++){
		cout<<sum<<' ';
		if(!pq.empty()){
			sum += pq.top();
			pq.pop();
		}
	}
	cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
