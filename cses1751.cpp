#include <bits/stdc++.h>
using namespace std;

int v[(int)1e5*2+5] = {};
int indeg[(int)1e5*2+5] = {};
int depth[(int)1e5*2+5] = {};
void getcycle(int now){
	int i =0;
	while(depth[now] == -2){
		i++;
		depth[now] = -3;
		now = v[now];
	}
	while(depth[now] == -3){
		depth[now] = i;
		now = v[now];
	}
	return;
}
void re(int now){
	depth[now] = -2;
	int nxt = v[now];
	if(depth[nxt] == -2){
		getcycle(nxt);
		return;
	}
	if(depth[nxt] == -1)re(nxt);
	if(depth[now] != -2)return;
	depth[now] = depth[nxt]+1;
	return;
}

int main(){
	int n;
	cin>>n;
	memset(depth,-1,sizeof(int)*((int)1e5*2+5));
	for(int i =0;i<n;i++){
		cin>>v[i];
		v[i]--;
		indeg[v[i]]++;
	}
	for(int i =0;i<n;i++){
		if(depth[i] == -1)re(i);
	}
	for(int i =0;i<n;i++)cout<<depth[i]<<' ';
}
