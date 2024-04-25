#include <bits/stdc++.h>
using namespace std;

int calc(int k){
	int re = 0;
	while(k){
		k/=10,re++;
	}
	return re;
}

void solve(){
	int n;
	cin>>n;
	multiset<int> a,b;
	priority_queue<int,vector<int>,less<int>> pq;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		a.insert(k);
		pq.push(k);
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		b.insert(k);
		pq.push(k);
	}
	int ans = 0;
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(a.find(now)!= a.end()&&b.find(now)!=b.end()){
			pq.pop();
			a.erase(a.find(now));
			b.erase(b.find(now));
			continue;
		}
		else if(a.find(now)!=a.end()){
			ans++;
			pq.push(calc(now));
			a.erase(a.find(now));
			a.insert(calc(now));
		}
		else{
			ans++;
			pq.push(calc(now));
			b.erase(b.find(now));
			b.insert(calc(now));
		}
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
