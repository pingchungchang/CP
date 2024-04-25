//#include "lib1740.h"
#include "1740_roads.h"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
int U[mxn],V[mxn],C[mxn],arr[mxn],dsu[mxn],sz[mxn],N,M,K;
int mx,mn;
set<int> ans;

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	a = root(a),b = root(b);
	if(a == b)return;
	if(sz[a]<sz[b])swap(a,b);
	dsu[b] = a;
	sz[a] += sz[b];
	return;
}

/*
void Init(int &a,int &b,int &c,int d[],int e[],int f[]){
	cin>>a>>b>>c;
	for(int i = 0;i<b;i++){
		cin>>d[i]>>e[i]>>f[i];
	}
	return;
}
void Solution(int a,int b,int c){
	cout<<a<<' '<<b<<' '<<c<<endl;
}
void NoSolution(){
	cout<<"No ans"<<endl;
}
*/



int main(){
	Init(N,M,K,U,V,C);
	for(int i = 0;i<M;i++)arr[i] = i;
	sort(arr,arr+M,[](int a,int b){return C[a]<C[b];});

	for(int i = 1;i<=N;i++)dsu[i] = i,sz[i] = 1;
	for(int i = 0;i<M;i++){
		int now = arr[i];
		int a = U[now],b = V[now],c = C[now];
		if(root(a) == root(b))continue;
		onion(a,b);
		mn += c;
	}

	for(int i = 1;i<=N;i++)dsu[i] = i,sz[i] = 1;
	for(int i = M-1;i>=0;i--){
		int now = arr[i];
		int a = U[now],b = V[now],c = C[now];
		if(root(a) == root(b))continue;
		onion(a,b);
		mx += c;
	}
	if(mx<N-1-K||mn>N-1-K){
		NoSolution();
		return 0;
	}

	for(int i = 1;i<=N;i++)dsu[i] = i,sz[i] = 1;

	int p = 0;
	while(p<M&&C[arr[p]] == 0)p++;
	for(int i = 0;i<p&&ans.size() != K;i++){
		int now = arr[i];
		int a = U[now],b = V[now],c = C[now];
		if(root(a) == root(b))continue;
		onion(a,b);
		ans.insert(now);
	}
	for(int i = M-1;i>=p;i--){
		int now = arr[i];
		int a = U[now],b = V[now],c = C[now];
		if(root(a) == root(b))continue;
		onion(a,b);
		ans.insert(now);
	}

	if(ans.size() != N-1){
		NoSolution();
		return 0;
	}
	int sum = 0;
	for(auto &i:ans)sum += C[i];
	assert(N-1-sum == K);
	for(auto &i:ans)Solution(U[i],V[i],C[i]);
	return 0;
}
