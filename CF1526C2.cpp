#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
	int n;
	cin>>n;
	priority_queue<ll,vector<ll>,greater<ll>> pq;
	vector<ll> v(n);
	for(int i = 0;i<n;i++){
		cin>>v[i];
	}
	ll hp = 0;
	for(int i =0;i<n;i++){
		hp+= v[i];
		pq.push(v[i]);
		if(hp<0){
			hp-=pq.top();
			pq.pop();
		}
	}
	cout<<pq.size();
}
