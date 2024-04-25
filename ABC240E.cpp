#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node{
	int par;
	pair<int,int> ran;
	vector<int> childs;
	node(){
		ran = make_pair(-1,-1);
		par = -1;
	}
};
vector<node> v;
int t = 1;
void dfs(int now){
	if(v[now].childs.size() == 1&&v[now].childs[0] == v[now].par){
		v[now].ran = make_pair(t,t);
		t++;
		return;
	}
	v[now].ran = make_pair(INT_MAX,0);
	for(auto i:v[now].childs){
		if(i == v[now].par)continue;
		v[i].par = now;
		dfs(i);
		v[now].ran.fs = min(v[now].ran.fs,v[i].ran.fs);
		v[now].ran.sc = max(v[now].ran.sc,v[i].ran.sc);
	}
	return;
}
int main(){
	int n;
	cin>>n;
	v = vector<node>(n,node());
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].childs.push_back(b);
		v[b].childs.push_back(a);
	}
	dfs(0);
	for(auto i:v){
		cout<<i.ran.fs<<' '<<i.ran.sc<<'\n';
	}
	return 0;
}

