#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e5+10;
int dsu[mxn];
vector<int> paths[mxn];
int col[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	dsu[root(a)] = root(b);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)dsu[i] = i;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		cin>>col[i];
	}
	for(int i = 1;i<=n;i++){
		for(auto nxt:paths[i])if(col[i] != col[nxt])onion(i,nxt);
	}
	for(int i = 1;i<=n;i++){
		for(auto nxt:paths[i]){
			if(col[nxt] == col[i]&&root(i) == root(nxt)){
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
}
