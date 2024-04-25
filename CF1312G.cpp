#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;

struct SEG{
#define mid ((l+r)>>1)
#define ls now*2+1
#define rs now*2+2
	int seg[mxn*4];
	SEG(){
		for(auto &i:seg)i = mxn*2;
	}
	void modify(int now,int l,int r,int s,int e,int v){
		if(l>=s&&e>=r){
			seg[now] = min(seg[now],v);
			return;
		}
		if(mid>=s)modify(ls,l,mid,s,e,v);
		if(mid<e)modify(rs,mid+1,r,mid+1,e,v+(mid+1-s));
	}
	int getval(int now,int l,int r,int p){
		if(l == r)return seg[now];
		int re = seg[now]+(p-l);
		if(mid>=p)return min(re,getval(ls,l,mid,p));
		else return min(re,getval(rs,mid+1,r,p));
	}
#undef ls
#undef rs 
#undef mid
};

vector<pair<char,int>> tree[mxn];
int dp[mxn];
int N,Q;
pii eul[mxn];
int req[mxn],qid[mxn];
int pt = 0;
SEG seg;

void dfs(int now){
	eul[now].fs = pt;
	if(qid[now])pt++;
	sort(tree[now].begin(),tree[now].end());
	for(auto nxt:tree[now]){
		dfs(nxt.sc);
	}
	eul[now].sc = pt;
}
void dfs1(int now){
	if(qid[now])dp[now] = min(dp[now],seg.getval(0,0,pt,eul[now].fs));
	if(eul[now].fs != eul[now].sc)seg.modify(0,0,pt,eul[now].fs,eul[now].sc-1,dp[now]+1);
	//cout<<now<<":"<<dp[now]<<' '<<eul[now].fs<<' '<<eul[now].sc-1<<"::"<<seg.getval(0,0,pt,eul[8].fs)<<endl;
	for(auto nxt:tree[now]){
		dp[nxt.sc] = dp[now]+1;
		dfs1(nxt.sc);
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++){
		int p;char c;
		cin>>p>>c;
		tree[p].push_back(make_pair(c,i));
	}
	cin>>Q;
	for(int i = 1;i<=Q;i++){
		int k;
		cin>>k;
		qid[k] = i;
		req[i] = k;
	}
	dfs(0);
	//for(int i = 1;i<=Q;i++)cout<<eul[req[i]].fs<<' ';cout<<endl;
	dfs1(0);
	for(int i = 1;i<=Q;i++)cout<<dp[req[i]]<<' ';cout<<'\n';
	return 0;
}
