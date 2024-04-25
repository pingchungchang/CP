#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,k;
	cin>>n>>k;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	for(int i = 0;i<n;i++){
		ll tmp;
		cin>>tmp;
		pq.push(tmp);
	}
	ll sum = 0;
	while(!pq.empty()&&pq.top()<=k){
		k -= pq.top();
		pq.pop();
		sum++;
	}
	cout<<sum<<' '<<k;
}
