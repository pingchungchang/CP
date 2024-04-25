#include <bits/stdc++.h>
using namespace std;

struct node{
	int par;
	vector<int> paths;
	int idx;
	node(){
		idx =-1;
		par = -1;
	}
};
vector<node> v;
vector<int> cycle;
int rt;
void color(int now,int p){
	int cp = now;
	while(v[now].idx != 2){
		now = v[now].par;
	}
	if(p == now&&now != rt)return;
	now = cp;
	while(v[now].idx != 2){
		v[now].idx = 2;
		cycle.push_back(now);
		now = v[now].par;
	}
	return;
}
void dfs(int now){
	for(auto nxt:v[now].paths){
		if(nxt == v[now].par)continue;
		if(v[nxt].idx == 2){
			color(now,nxt);
		}
		else if(v[nxt].idx == -1){
			v[nxt].idx = 1;
			v[nxt].par = now;
			dfs(nxt);
		}
	}
}
int getlen(int now){
	int returns = 0;
	for(auto nxt:v[now].paths){
		if(v[nxt].idx == 1){
			v[nxt].idx = 3;
			returns ++;
			returns += getlen(nxt);
		}
	}
	return returns;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	v = vector<node>(n,node());
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].paths.push_back(b);
		v[b].paths.push_back(a);
	}
	cin>>rt;
	rt--;
	v[rt].idx = 2;
	dfs(rt);
	pair<int,int> ans = make_pair(0,0);
	for(auto j:v[rt].paths){
		if(v[j].idx != 2)cycle.push_back(j);
	}
	sort(cycle.begin(),cycle.end());
	for(auto i:cycle){
		int k = getlen(i);
		if(v[i].idx != 2)k--;
		if(ans.first<k){
			ans = make_pair(k,i);
		}
	}
	int total = 0;
	for(int i = 0;i<n;i++)if(v[i].idx != -1)total ++;
	if(ans.first == 0)cout<<0;
	else cout<<ans.second+1<<' '<<total-ans.first;
}

/*
6 7
1 3
3 4
5 1
2 6
4 5
6 3
5 3
4

5 4
1 2
1 3
2 3
4 5
1

7 7
1 2
2 3
3 1
1 4
4 5
5 6
6 7

*/
