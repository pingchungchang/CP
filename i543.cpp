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

int n;
void solve(){
	priority_queue<int,vector<int>,less<int>> pq;
	int ans = n;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		pq.push(k);
	}
	for(int i = 0;i<n;i++){
		ans = min(ans,pq.top()+i);
		pq.pop();
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	while(cin>>n)solve();
}

