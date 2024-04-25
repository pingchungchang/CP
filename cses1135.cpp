#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
	int par;
	vector<int> childs;
	int depth;
	int an[31];
	node(){
		memset(an,0,sizeof(an));
		par = -1;
		depth = -1;
	}
};
vector<node> v;
void getdepth(int now){
	v[now].an[0] = v[now].par;
	for(int i = 1;i<31;i++){
		if((1<<i)<=v[now].depth)v[now].an[i] = v[v[now].an[i-1]].an[i-1];
	}
	for(auto nxt:v[now].childs){
		if(nxt != v[now].par){
			v[nxt].depth = v[now].depth+1;
			v[nxt].par = now;
			getdepth(nxt);
		}
	}
	return;
}

int lca(int a,int b){
	if(v[a].depth!=v[b].depth){
		if(v[b].depth>v[a].depth)swap(a,b);
		int dist = v[a].depth-v[b].depth;
		for(int i = 30;i>=0;i--){
//			cout<<a<<' '<<b<<' '<<dist<<endl;
			if((1<<i)<=dist){
				a = v[a].an[i];
//				cout<<(1<<i)<<','<<dist<<'\n';
			}
			dist = v[a].depth-v[b].depth;
		}
	}
	for(int i = 30;i>=0;i--){
		if(v[a].an[i] != v[b].an[i]){
			a = v[a].an[i];
			b = v[b].an[i];
		}
	}
	if(a == b)return a;
	else return v[a].par;
}
int main(){
	io
	int n,q;
	cin>>n>>q;
	v = vector<node>(n);
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		v[a].childs.push_back(b);
		v[b].childs.push_back(a);
	}
	v[0].par = 0;
	for(int i = 0;i<31;i++)v[0].an[i] = 0;
	v[0].depth = 0;
	getdepth(0);
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		int anc = lca(a,b);
//		cout<<anc<<' ';
		cout<<v[a].depth+v[b].depth-2*v[anc].depth<<'\n';
	}
}


/*
10 10
7 10
4 8
6 2
4 3
7 5
10 3
5 1
6 1
2 9
3 4
4 3
4 4
8 10
6 4
2 8
6 4
5 9
5 9
5 9

1
1
0
3
6
8
6
4
4
4
*/
