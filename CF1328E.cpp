#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
vector<int> tree[mxn];
pii eul[mxn];
int par[mxn],dep[mxn];
int C = 0;

void dfs(int now){
	eul[now].fs = ++C;
	for(auto nxt:tree[now]){
		if(nxt == par[now])continue;
		par[nxt] = now;
		dep[nxt] = dep[now]+1;
		dfs(nxt);
	}
	eul[now].sc = C;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	par[1] = 1;
	dep[1] = 0;
	dfs(1);
	while(q--){
		int k;
		cin>>k;
		int arr[k];
		for(auto &i:arr)cin>>i,i = par[i];
		sort(arr,arr+k,[](int a,int b){return dep[a]<dep[b];});
		int lst = arr[k-1];
		bool flag = true;
		for(auto &i:arr){
			if(eul[i].sc<eul[lst].fs||eul[i].fs>eul[lst].fs)flag = false;
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
