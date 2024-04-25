#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>


const int mxn = 2e5+10;
ll ans[mxn];
priority_queue<int,vector<int>,greater<int>> pq;
priority_queue<pll,vector<pll>,greater<pll>> wait;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		pq.push(i);
	}
	for(int i = 0;i<m;i++){
		ll t,w,s;
		cin>>t>>w>>s;
		while(!wait.empty()&&wait.top().fs<=t){
			pq.push(wait.top().sc);
			wait.pop();
		}
		if(pq.empty())continue;
		ans[pq.top()] += w;
		wait.push(make_pair(t+s,pq.top()));
		pq.pop();
	}
	for(int i = 1;i<=n;i++){
		cout<<ans[i]<<'\n';
	}
}
