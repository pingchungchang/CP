#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
struct node{
	int val;
	int par;
	vector<pii> childs;
	node(){
		par = -1;
		val = 1;
	}
};

int n,root,k;
vector<node> v;

void dfs(int now){
	for(auto nxt:v[now].childs){
		if(nxt.fs == v[now].par)continue;
		v[nxt.fs].par = now;
		dfs(nxt.fs);
		if(nxt.sc>=k){
			v[now].val += v[nxt.fs].val;
		}
	}
//	cout<<now<<' '<<v[now].val<<"  "<<v[now].par<<'\n';
	return;
}
int main(){
	cin>>n>>root>>k;
	root--;
	v = vector<node>(n,node());
	for(int i = 0;i<n-1;i++){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		v[a].childs.push_back(make_pair(b,c));
		v[b].childs.push_back(make_pair(a,c));
	}
	dfs(root);
	cout<<v[root].val-1;
}

