#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


void solve(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c = 0;
	for(auto &i:s)if(i == 'L')c++;
	m = min(m,c);
	int ans = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == 'W')ans++;
		if(i != 0&&s[i] == s[i-1]&&s[i] == 'W')ans++;
	}
	int st = n;
	int ed = 0;
	for(int i = 0;i<n;i++){
		if(s[i] == 'W')st = min(st,i),ed = max(i,ed);
	}
	if(st>ed){
		cout<<max(0,m*2-1)<<'\n';
		return;
	}
	vector<int> v;
	for(int i = st;i<ed;i++){
		if(s[i] == 'W')v.push_back(0);
		else v.back()++;
	}
	priority_queue<int,vector<int>,greater<int>> pq;
	for(auto &i:v)if(i)pq.push(i);
	while(!pq.empty()&&pq.top()<=m){
		m -= pq.top();
		ans += pq.top()*2+1;
		pq.pop();
	}
	ans += m*2;
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
