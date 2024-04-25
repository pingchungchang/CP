#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void solve(){
	int n;
	cin>>n;
	priority_queue<ll,vector<ll>,less<ll>> pq;
	ll sum = 0;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		sum += k;
		pq.push(k);
	}
	priority_queue<ll,vector<ll>,less<ll>> q;
	q.push(sum);
	while(!q.empty()&&!pq.empty()&&q.top()>=pq.top()){
		while(!q.empty()&&!pq.empty()&&q.top() == pq.top()){
			q.pop();
			pq.pop();
		}
		if(pq.empty())break;
		ll a = (q.top()+1)/2;
		ll b = q.top()/2;
		q.pop();
		q.push(a);
		q.push(b);
	}
	if(pq.empty()){
		cout<<"Yes\n";
	}
	else cout<<"No\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}

