#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n,m;
	cin>>n>>m;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			int tmp = max(i+j,n-1-i+m-1-j);
			tmp = max(n-1-i+j,tmp);
			tmp = max(tmp,i+m-1-j);
			pq.push(tmp);
		}
	}
	while(!pq.empty()){
		cout<<pq.top()<<' ';
		pq.pop();
	}
	cout<<'\n';
	return;
}
int main(){
	int t;
	cin>>t;
	while(t--)solve();
}

