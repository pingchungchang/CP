#include <bits/stdc++.h>
using namespace std;

struct node{
	vector<int> child;
	vector<int> path;
	bool goneto;
	int s;
	node(){
		s = 0;
		goneto = false;
	}
};
vector<node> v;
void maketree(int now){
	v[now].goneto = true;
	for(int i = 0;i<v[now].path.size();i++){
		int nxt = v[now].path[i];
		if(v[nxt].goneto == false){
			maketree(nxt);
			v[now].s += v[nxt].s;
		}
	}
	v[now].s+=1;
	return;
}
void solve(){
	int k;
	cin>>k;
	k--;
	cout<<v[k].s<<'\n';
}
int main(){
	int n,m,r;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>r;
	v = vector<node>(n,node());
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].path.push_back(b);
		v[b].path.push_back(a);
	}
	maketree(r-1);
	for(int i = 0;i<m;i++){
		solve();
	}
}
