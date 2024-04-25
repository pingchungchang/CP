#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int>> pq;
	ll ans = 0;
	for(int i= 0;i<n;i++){
		int k;
		cin>>k;
		pq.push(k);
	}
	while(pq.size()>1){
		auto ta = pq.top();pq.pop();
		auto tb = pq.top();pq.pop();
		ans += ta+tb;
		pq.push(ta+tb);
	}
	cout<<ans;
}
