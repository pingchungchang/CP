#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e6+10;

struct F_Stack{
	int ptr ;
	int arr[mxn];
	F_Stack(){
		memset(arr,0,sizeof(arr));
		ptr = 0;
	}
	void push_back(int k){
		arr[++ptr] = k;
		return;
	}
	void pop_back(){
		ptr--;
		return;
	}
	int back(){
		return arr[ptr];
	}
};


int cnt[mxn],tans,rid;
int op[mxn];
vector<int> req[mxn];
vector<int> tree[mxn];
int pt,pid,ans[mxn];
int dep[mxn],dfn[mxn];
vector<int> pos;
int par[mxn][20];

inline void add(int k){
	if(!cnt[k])tans++;
	cnt[k]++;
	return;
}

inline void del(int k){
	cnt[k]--;
	if(!cnt[k])tans--;
}

void dfs(int now){
	if(now)add(op[now]);
	for(auto &i:req[now])ans[i] = tans;
	for(auto nxt:tree[now])dfs(nxt);
	if(now)del(op[now]);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>q;
	#define endl '\n'
	pos.reserve(mxn);
	pos.push_back(0);
	dep[0] = 0;
	while(q--){
		char c;
		cin>>c;
		if(c == '?'){
			req[pt].push_back(rid++);
		}
		else if(c == '!'){
			pos.pop_back();
			pt = pos.back();
		}
		else if(c == '+'){
			int k;
			cin>>k;
			pid++;
			tree[pt].push_back(pid);
			dep[pid] = dep[pt]+1;
			op[pid] = k;
			pos.push_back(pid);
			dfn[dep[pid]] = pid;
			par[pid][0] = pt;
			for(int i = 1;i<20;i++){
				par[pid][i] = par[par[pid][i-1]][i-1];
			}
			pt = pid;
		}
		else{
			int k;
			cin>>k;
			for(int i = 0;i<20;i++)if((1<<i)&k)pt = par[pt][i];
			pos.push_back(pt);
		}
	}
	dfs(0);
	for(int i = 0;i<rid;i++)cout<<ans[i]<<'\n';
	return 0;
}

