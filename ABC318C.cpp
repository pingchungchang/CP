#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,d,p;
	cin>>n>>d>>p;
	priority_queue<ll,vector<ll>,less<ll>> pq;
	ll sum = 0;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		pq.push(k);
		sum += k;
	}
	ll ans = sum;
	while(!pq.empty()){
		for(int i = 0;i<d;i++){
			if(!pq.empty()){
				sum -= pq.top();
				pq.pop();
			}
		}
		sum += p;
		ans = min(ans,sum);
	}
	cout<<ans;
}
