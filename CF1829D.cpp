#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	queue<int> q;
	unordered_set<int> done;
	q.push(n);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(now == m){
			cout<<"YES\n";
			return;
		}
		if(now%3 != 0)continue;
		if(done.find(now/3)==done.end()){
			done.insert(now/3);
			q.push(now/3);
		}
		if(done.find(now/3*2)==done.end()){
			done.insert(now/3*2);
			q.push(now/3*2);
		}
	}
	cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
