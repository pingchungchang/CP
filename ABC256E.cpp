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
	int n;
	cin>>n;
	vector<ll> vals(n+1,0),dir(n+1,0),diff(n+1,0);
	for(int i = 1;i<=n;i++){
		cin>>dir[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>diff[i];
		vals[dir[i]] += diff[i];
	}
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	for(int i = 1;i<=n;i++){
		pq.push(make_pair(vals[i],i));
	}
	ll ans = 0;
	bool goneto[n+1] = {};
	while(!pq.empty()){
		pll now = pq.top();
//		cout<<now.fs<<' '<<now.sc<<endl;
		pq.pop();
		if(goneto[now.sc])continue;
		goneto[now.sc] = true;
		ans += now.fs;
		ll nxt = dir[now.sc];
		if(goneto[nxt] == false){
			vals[nxt] -= diff[now.sc];
			pq.push(make_pair(vals[nxt],nxt));
		}
	}
	cout<<ans;
}

