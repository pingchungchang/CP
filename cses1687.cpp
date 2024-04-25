#include <bits/stdc++.h>
using namespace std;

struct node{
	int par;
	vector<int> dist;
	node(){
		dist = vector<int>(20,-2);
		par = -2;
	}
};
int n;
int q;
vector<node> v;
int findpar(int now,int k){
	if(k == 0)return now;
	if(now == -2)return now;
	for(int i = 20;i>=0;i--){
		if((1<<i)<=k)return findpar(v[now].dist[i],k-(1<<i));
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	v = vector<node>(n);
	for(int i = 1;i<n;i++){
		int k;
		cin>>k;
		v[i].par = k-1;
	}
	for(int i = 1;i<n;i++){
		v[i].dist[0] = v[i].par;
		for(int j = 1;(1<<j)<=n;j++){
			int pre = v[i].dist[j-1];
			if(pre != -2)v[i].dist[j] = v[pre].dist[j-1];
//			cout<<v[i].dist[j]<<' ';
		}
//		cout<<endl;
	}
	for(int i = 0;i<q;i++){
		int a,b;
		cin>>a>>b;
		cout<<findpar(a-1,b)+1<<' ';
	}
//	cout<<endl;
//	for(int i = 0;i<n;i++){
//		for(int j = 0;j<16;j++)cout<<v[i].dist[j]<<" ";
//		cout<<endl;
//	}
}
