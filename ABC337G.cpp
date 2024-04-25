#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
ll bit1[mxn],bit2[mxn];
int par[mxn];
pii eul[mxn];
vector<int> tree[mxn];
ll N;
int pp = 0;

void dfs(int now,int fa){
	eul[now].fs = ++pp;
	for(auto nxt:tree[now]){
		if(nxt == fa)continue;
		par[nxt] = now;
		dfs(nxt,now);
	}
	eul[now].sc = pp;
	return;
}

void modify(ll bit[],int p,ll v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
inline ll getval(ll bit[],int s,int e = -1){
	if(e == -1){
		swap(s,e);
	}
	ll re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<N;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1,1);
	for(int i = 1;i<=N;i++)modify(bit1,eul[i].fs,1);
	for(int i = N;i>=1;i--){
		modify(bit1,eul[i].fs,-1);
		int sz = i-1;
		for(auto nxt:tree[i]){
			if(nxt == par[i])continue;
			int tmp = sz-getval(bit1,eul[nxt].fs,eul[nxt].sc);
			//cout<<i<<' '<<nxt<<":"<<tmp<<' '<<sz<<endl;
			modify(bit2,eul[nxt].fs,tmp);
			modify(bit2,eul[nxt].sc+1,-tmp);
		}
		int tmp = getval(bit1,eul[i].fs,eul[i].sc);
		modify(bit2,1,tmp);
		modify(bit2,eul[i].fs,-tmp);
		modify(bit2,eul[i].sc+1,tmp);
	}
	for(int i = 1;i<=N;i++){
		cout<<getval(bit2,eul[i].fs)+i-1<<' ';
	}
	return 0;
}
