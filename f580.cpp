#include <bits/stdc++.h>
using namespace std;

struct dice{
	int f;
	int b;
	int r;
	int l;
	int u;
	int d;
	dice(){
		u=1;
		f=4;
		r=2;
		d=6;
		b=3;
		l=5;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	vector<dice> v(n);
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;
		if(b == -1){
			vector<int> v2(4);
			v2[0] = v[a].u;
			v2[1] = v[a].f;
			v2[2] = v[a].d;
			v2[3] = v[a].b;
			v[a].u = v2[3];
			v[a].f = v2[0];
			v[a].d = v2[1];
			v[a].b = v2[2];
		}
		else if(b == -2){
			vector<int> v2(4);
			v2[0] = v[a].r;
			v2[1] = v[a].u;
			v2[2] = v[a].l;
			v2[3] = v[a].d;
			v[a].u = v2[2];
			v[a].r = v2[1];
			v[a].d = v2[0];
			v[a].l = v2[3];
		}
		else{
			b--;
			swap(v[a],v[b]);
		}
	}
	for(int i = 0;i<n;i++)cout<<v[i].u<<' ';
}
