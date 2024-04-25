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
#pragma GCC optimize("O3")

struct node{
	ll s,e,id;
	ll buy,sell;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	node(){
		id = 0;
		s = e= buy = sell = 0;
	}
};
const int mxn = 1e6+10;
int cc = 0;
vector<ll> paths[mxn*2];
vector<ll> all;
ll deg[mxn];
node arr[mxn];
queue<ll> q;
priority_queue<ll,vector<ll>,greater<ll>> ans;
priority_queue<pll,vector<pll>,greater<pll>>buf;
const ll mod = 1e9+7;
void solve(){
	ll n,k;
	cin>>n>>k;
	
	all.clear();
	while(!buf.empty())buf.pop();
	for(int i = 0;i<=n*2;i++)paths[i].clear();
	for(int i = 0;i<=n;i++)deg[i] = 0;
	while(!q.empty())q.pop();
	while(!ans.empty())ans.pop();
	
	for(int i = 1;i<=n;i++){
		arr[i].id = i;
		cin>>arr[i].s>>arr[i].e>>arr[i].buy>>arr[i].sell;
		all.push_back(arr[i].s);
		all.push_back(arr[i].e);
	}
	sort(_all(all));
	all.erase(unique(_all(all)),all.end());
	for(int i = 1;i<=n;i++){
		arr[i].s = lower_bound(_all(all),arr[i].s)-all.begin();
		arr[i].e = lower_bound(_all(all),arr[i].e)-all.begin();
		paths[arr[i].s].push_back(arr[i].id);
	}
	for(int i = 1;i<=n;i++){
		if(!paths[arr[i].e].empty())deg[paths[arr[i].e][0]]++;
	}
//	cout<<n<<endl;
	for(int i = 1;i<=n;i++){
		if(deg[i] == 0){
			arr[i].pq.push(0);
			q.push(i);
		}
	}
	while(!q.empty()){
		auto now = q.front();
		cout<<now<<" : ";
		q.pop();
		ll nxt = -1;
		if(!paths[arr[now].e].empty())nxt = paths[arr[now].e][0];
		while(!arr[now].pq.empty()){
			if(nxt != -1){
				arr[nxt].pq.push(arr[now].pq.top()-arr[now].sell);
			}
			ans.push(arr[now].pq.top());
			cout<<arr[now].pq.top()<<' ';
			arr[now].pq.pop();
		}
		cout<<'\n';
		while(nxt != -1&&arr[nxt].pq.size()>k)arr[nxt].pq.pop();
		while(ans.size()>k)ans.pop();
		if(nxt != -1)deg[nxt]--;
		if(nxt != -1&&deg[nxt] == 0){
			while(!buf.empty())buf.pop();
			while(!arr[nxt].pq.empty()){
				buf.push(arr[nxt].pq.top());
				arr[nxt].pq.pop();
			}
			while(!buf.empty()){
				for(auto &tt:paths[arr[now].e]){
					if(buf.top()+arr[tt].buy>0)arr[tt].pq.push(buf.top()+arr[tt].buy);
				}
				buf.pop();
			}
			for(auto &tt:paths[arr[now].e]){
//				arr[tt].pq.push(-arr[tt].sell);
				arr[tt].pq.push(0);
			}
			for(auto &tt:paths[arr[now].e])while(arr[tt].pq.size()>k)arr[tt].pq.pop();
			for(auto &tt:paths[arr[now].e])q.push(tt);
		}
	}
	ll total = 0;
	while(!ans.empty()&&ans.top()>0){
		total += ans.top();
//		cout<<ans.top()<<' ';
		total %= mod;
		ans.pop();
	}
	cout<<"Case #"<<++cc<<": "<<total<<'\n';
	cout<<endl;
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

