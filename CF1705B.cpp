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
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	for(int i = 0;i<n-1;i++){
		if(v[i] != 0)pq.push(make_pair(i,v[i]));
	}
	if(pq.empty()){
		cout<<"0\n";
		return;
	}
	ll ans = 0;
	int s = pq.top().fs;
	for(int i = s;i<n-1;i++){
		if(v[i]!=0)continue;
		else{
			ans++;
			auto now = pq.top();
			pq.pop();
			now.sc--;
			v[i] = 1;
			if(now.sc>0)pq.push(now);
			pq.push(make_pair(i,1));
		}
	}
	while(!pq.empty()){
		ans += pq.top().sc;
		pq.pop();
	}
	cout<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

