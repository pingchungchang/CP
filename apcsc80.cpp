#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	io
	priority_queue<int,vector<int>,greater<int>> pq;
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		pq.push(k);
	}
	while(m--){
		int t;
		cin>>t;
		if(t == 0){
			cout<<pq.top()<<'\n';
		}
		else if(t == 1){
			int tmp = pq.top();
			pq.pop();
			cout<<pq.top()<<'\n';
			pq.push(tmp);
		}
		else if(t == 2){
			pq.pop();
		}
		else{
			int k;
			cin>>k;
			pq.push(k);
		}
	}
}

