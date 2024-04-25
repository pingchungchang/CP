#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int former;
	int latter;
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	vector<node> v(n);
	for(int i =0;i<n-1;i++){
		v[i].latter = i+1;
	}
	for(int i =1;i<n;i++)v[i].former = i-1;
	v[n-1].latter = 0;
	v[0].former = n-1;
	for(int i =0;i<m;i++){
		char type;
		int a,b;
		cin>>type>>a>>b;
		if(a == b)continue;
		v[v[a].former].latter = v[a].latter;
		v[v[a].latter].former = v[a].former;
		if(type == 'R'){
			v[v[b].latter].former = a;
			v[a].latter = v[b].latter;
			v[a].former = b;
			v[b].latter = a;
		}
		else{
			v[v[b].former].latter = a;
			v[a].former = v[b].former;
			v[a].latter = b;
			v[b].former = a;
		}
	}
	for(int i =0;i<q;i++){
		int k;
		cin>>k;
		cout<<v[k].former<<' '<<v[k].latter<<' ';
	}
	return 0;
}
