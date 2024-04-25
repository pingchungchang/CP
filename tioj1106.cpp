#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string s;

const int mxn = 1e5+10;
vector<int> tree[mxn];
int par[mxn];
int dep[mxn];
int pt = 0;
int n;

void solve(){
	for(int i = 0;i<=pt;i++){
		tree[i].clear();
		dep[i] = par[i] = 0;
	}
	n = s.size();
	int now = 0;
	pt = 0;
	dep[now] = 0;
	for(auto &i:s){
		if(i == '*'){
			tree[now].push_back(++pt);
			dep[pt] = dep[now]+1;
			par[pt] = now;
		}
		else if(i == '('){
			tree[now].push_back(++pt);
			par[pt] = now;
			dep[pt] = dep[now]+1;
			now = pt;
		}
		else if(i == ')'){
			now = par[now];
		}
		else assert(false);
	}
	assert(now == 0);
	int leaf = 0,deep = 0,nary = 0;
	for(int i = 1;i<=pt;i++){
		if(tree[i].empty())leaf++;
		deep = max(deep,dep[i]);
		nary = max(nary,(int)tree[i].size());
	}
	cout<<leaf<<' '<<deep<<' '<<nary<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(getline(cin,s))solve();
}
