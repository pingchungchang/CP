#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


struct mat{
	int base[20];
	mat(){
		memset(base,0,sizeof(base));
	}
	int add(int k){
		for(int i = 19;i>=0;i--){
			if(k&(1<<i)){
				if(!base[i]){
					base[i] = k;
					break;
				}
				else k ^= base[i];
			}
		}
		return k;
	}
	int& operator[](int k){
		return base[k];
	}
	mat operator+(mat b)const{
		auto re = (*this);
		for(int i = 0;i<20;i++)if(b[i])re.add(b[i]);
		return re;
	}
};

const int mxn = 2e5+10;
vector<int> tree[mxn];
int par[mxn][20];
mat basis[mxn][20];
int n,q;
int arr[mxn];
int dep[mxn];

void dfs(int now){
	for(int i = 1;i<20;i++){
		par[now][i] = par[par[now][i-1]][i-1];
		basis[now][i] = basis[now][i-1]+basis[par[now][i-1]][i-1];
	}
	for(auto nxt:tree[now]){
		if(nxt == par[now][0])continue;
		dep[nxt] = dep[now]+1;
		par[nxt][0] = now;
		basis[nxt][0].add(arr[now]);
		dfs(nxt);
	}
}

mat lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	int d = dep[a]-dep[b];
	mat re;
	re.add(arr[a]);
	re.add(arr[b]);
	for(int i = 19;i>=0;i--){
		if(d&(1<<i)){
			re = re+basis[a][i];
			a = par[a][i];
		}
	}
	for(int i =  19;i>=0;i--){
		if(par[a][i] != par[b][i]){
			re = re+basis[a][i];
			re = re+basis[b][i];
			a = par[a][i];
			b = par[b][i];
		}
	}
	if(a != b)re = re+basis[a][0];
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	par[1][0] = 1;
	dfs(1);
	//for(int i = 0;i<20;i++)cout<<basis[3][19][i]<<' ';cout<<endl;
	cin>>q;
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		auto re = lca(a,b);
		if(!re.add(c))cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
