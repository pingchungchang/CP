#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const int mxn = 2e5+10;
bitset<mxn> goneto;
int cycle = 0;
vector<int> tree[mxn];

struct node{
	node* nxt[2];
	int idx;
	int cnt;
	node(){
		nxt[0] = nxt[1] = 0;
		idx = 0;
		cnt = 0;
	}
};

node* trie = new node();

int dfs(int now,int par){
	cout<<now<<' '<<par<<'\n';
	int re = 1;
	goneto[now]  = true;
	for(auto nxt:tree[now]){
		if(goneto[nxt]){
			if(nxt != par)cycle = 1;
		}
		else{
			re += dfs(nxt,now);
		}
	}
	return re;
}
int main(){
	io
	int n;
	cin>>n;
	vector<int> v(n+1);
	vector<int> ans(n+1);
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		int re = 0;
		v[i] = k;
		for(int j= 0;j<30;j++){
			re<<=1;
			re ^= (k&1);
			k>>=1;
		}
		node* now = trie;
		for(int j = 0;j<30;j++){
			now->cnt++;
			if(!now->nxt[re&1])now->nxt[re&1] = new node();
			now = now->nxt[re&1];
			re>>=1;
		}
		now->idx = i;
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++)cout<<(v[i]^v[j])<<' ';cout<<endl;
	}
	for(int i = 1;i<=n;i++){
		auto now = trie;
		int re = 0;
		for(int j = 0;j<30;j++){
			re<<=1;
			re ^= (v[i]&1);
			v[i]>>=1;
		}
		int diff = 0;
		for(int j = 0;j<30;j++){
			if(!now->nxt[re&1]||(diff == 0&&now->nxt[re&1]->cnt <= 1)){
				now = now->nxt[1-(re&1)];
				diff++;
				cout<<1-(re&1);
			}
			else{
				now = now->nxt[re&1];
				cout<<(re&1);
			}
			re>>=1;
		}
		cout<<endl;
		ans[i] = now->idx;
	}
	int tt = INT_MAX;
	for(int i = 1;i<=n;i++){
		tree[i].push_back(ans[i]);
		tree[ans[i]].push_back(i);
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
	for(int i = 1;i<=n;i++){
		if(!goneto[i]){
			cycle = 0;
			int s = dfs(i,i);
			tt = min(tt,n-s+cycle);
			cout<<i<<' '<<tt<<endl<<endl;
		}
	}
	cout<<tt;
	
}

