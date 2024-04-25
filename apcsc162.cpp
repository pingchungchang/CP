#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int main(){
	io
	int n;
	cin>>n;
	priority_queue<int,vector<int>,less<int>> pq1,pq2;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		pq1.push(k);
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		pq2.push(k);
	}
	while(!pq1.empty()&&!pq2.empty()){
		while(!pq1.empty()&&pq1.top()>=pq2.top())pq1.pop();
		if(!pq1.empty()){
			ans++;
			pq1.pop();
			pq2.pop();
		}
	}
	cout<<ans;
}

