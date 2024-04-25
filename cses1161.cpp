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
	cin>>n>>n;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		pq.push(k);
	}
	ll ans = 0;
	while(pq.size()>1){
		int ta = pq.top();pq.pop();
		int tb = pq.top();pq.pop();
		ans += ta+tb;
		pq.push(ta+tb);
	}
	cout<<ans;
}
