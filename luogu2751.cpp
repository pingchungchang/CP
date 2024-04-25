#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1010;
ll fin[mxn];
priority_queue<pll,vector<pll>,greater<pll>> pq;
ll ans1,ans2;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i = 0;i<m1;i++){
		int k;
		cin>>k;
		pq.push(make_pair(k,k));
	}
	for(int i = 0;i<n;i++){
		auto now = pq.top();
		pq.pop();
		ans1 = now.fs;
		fin[i] = now.fs;
		now.fs += now.sc;
		pq.push(now);
	}
	while(!pq.empty())pq.pop();
	for(int i = 0;i<m2;i++){
		int k;
		cin>>k;
		pq.push(make_pair(k,k));
	}
	for(int i = n-1;i>=0;i--){
		auto now = pq.top();
		pq.pop();
		ans2 = max(ans2,now.fs+fin[i]);
		now.fs += now.sc;
		pq.push(now);
	}
	cout<<ans1<<' '<<ans2;
}
