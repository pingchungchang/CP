#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct edge{
	string name;
	ll s,e,val;
	int id;
	edge(){
		s = e = val = 0;
		id =0;
	}
	edge(ll sss,ll eee,ll vv,string ss){
		name = ss;
		s = sss,e = eee,val = vv;
	}
};
class cmp{
	public:
		bool operator(edge &a,edge &b){
			if(a.val != b.val)return a.val>b.val;
			else return a.id>b.id;
		}
};
const int mxn = 55;
ll n,m;
const ll inf = 1e9;
vector<edge> paths[mxn];
string city[mxn];
string pre[mxn];
ll dist[mxn];
vector<edge> ans;
void prim(int start){
	priority_queue<edge,vector<edge>,cmp> pq;
}
void solve(){
	ans.clear();
	for(int i = 1;i<=n;i++){
		cin>>city[i];
		paths[i].clear();
		
		dist[i] = inf;
	}
	cin>>m;
	for(int i = 0;i<m;i++){
		edge tmp;
		cin>>tmp.name>>tmp.s>>tmp.e>>tmp.val;
		tmp.id = i;
		paths[tmp.s].push_back(tmp);
	}
	string start;
	cin>>start;
	int st = 0;
	for(int i = 1;i<=n;i++){
		if(city[i] == start)st = i;
	}
	prim(i);
}
int main(){
	while(cin>>n){
		if(!n)return 0;
		solve();
	}
}
