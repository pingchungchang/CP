#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int inf = 1e9;

void solve(){
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 0;i<n*(n-1)/2;i++){
		int k;
		cin>>k;
		pq.push(k);
	}
	int c = 0;
	vector<int> ans;
	for(int i = 0;i<n-1;i++){
		auto now = pq.top();
		for(int j = 0;j<n-i-1;j++)pq.pop();
		ans.push_back(now);
	}
	ans.push_back(inf);
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
