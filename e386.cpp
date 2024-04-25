#include <bits/stdc++.h>
using namespace std;
#define ll long long
//failed

int main(){
	ll p,n;
	cin>>p>>n;
	vector<pair<ll,ll>> v(n+1,make_pair(0,0));
	for(int i = 0;i<n;i++){
		cin>>v[i].second>>v[i+1].first;
		v[i+1].first += v[i].first;
	}
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
	vector<ll> dp(n+1,-1);
	dp[0] = 0;
	pq.push(make_pair(v[0].second,v[0].first));
	for(int i = 1;i<=n;i++){
//		cout<<pq.top().first<<',';
		while(pq.top().second<v[i].first-p){
			pq.pop();
		}
		dp[i] = pq.top().first*(v[i].first-v[i-1].first)+dp[i-1];
		pq.push(make_pair(v[i].second,v[i].first));
	}
//	cout<<endl;
//	for(int i = 0;i<v.size();i++)cout<<v[i].first<<' ';
//	cout<<endl;
//	for(int i = 0;i<=n;i++)cout<<dp[i]<<' ';
//	return 0;
	cout<<dp[n];
	
}
