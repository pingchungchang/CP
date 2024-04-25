#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e5+10;
const int sq = sqrt(mxn);

int cnt[mxn];
int C = 0;
pii pos[mxn];
vector<int> paths[mxn];
vector<int> edges;
int pl,pr;
int ans[mxn];
int n,m,q;

struct Q{
	int l,r,id;
	Q(){
		l = r = id = 0;
	}
	Q(int a,int b,int c){
		l = a,r = b,id = c;
	}
	const bool operator<(const Q& b)const{
		return (l/sq == b.l/sq?(l/sq&1?r>b.r:r<b.r):l<b.l);
	}
};
vector<Q> req;

inline void add(int p){
	int now = edges[p];
	if(!cnt[now])C++;
	cnt[now]++;
	return;
}
inline void del(int p){
	int now = edges[p];
	cnt[now]--;
	if(!cnt[now])C--;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i = 0;i<m;i++){
		int a,b;
		cin>>a>>b;
		paths[a].push_back(b);
		paths[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		pos[i].sc = pos[i].fs = edges.size();
		edges.push_back(i);
		for(auto &j:paths[i]){
			pos[i].sc = edges.size();
			edges.push_back(j);
		}
	}
	/*
	for(auto &i:edges)cout<<i.fs<<' '<<i.sc<<',';cout<<endl;
	for(int i = 1;i<=n;i++)cout<<pos[i].fs<<' '<<pos[i].sc<<',';cout<<endl;

   */
	for(int i = 0;i<q;i++){
		int l,r;
		cin>>l>>r;
		Q tmp(pos[l].fs,pos[r].sc,i);
		if(tmp.r<tmp.l){
			assert(false);
		}
		else ans[i] = -(r-l+1),req.push_back(tmp);
	}
	sort(req.begin(),req.end());
	pl = pr = 0;
	add(0);
	for(auto &i:req){
		while(pr<i.r)add(++pr);
		while(pl>i.l)add(--pl);
		while(pr>i.r)del(pr--);
		while(pl<i.l)del(pl++);
		ans[i.id] += C;
		//cout<<i.l<<' '<<i.r<<','<<i.id<<' '<<C<<endl;
	}
	for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';
}
