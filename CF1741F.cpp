#include <bits/stdc++.h>
using namespace std;

#define _all(T) T.begin(),T.end()
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define mid ((l+r)>>1)

const int mxn = 2e5+10;
const int inf = 1e9+10;
struct node{
	int tag,val;
	node(){}
};
node segtree[mxn*8];
vector<int> all;
int ans[mxn];
vector<tuple<int,int,int>> req[mxn];

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].tag += v;
		return;
	}
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].val = segtree[now*2+1].val+segtree[now*2+2].val+segtree[now*2+2].tag+segtree[now*2+1].tag;
	return;
}

int getval(int now,int l,int r,int p,int tp){
	if(segtree[now].tag != 0){
		if(tp == 0)return r<=p?all[r]:all[p];
		else return l>=p?all[l]:all[p];
	}
	if(tp == 0&&r<=p)return segtree[now*2+2].tag+segtree[now*2+2].val?getval(now*2+2,mid+1,r,p,tp):getval(now*2+1,l,mid,p,tp);
	if(tp == 1&&l>=p)return segtree[now*2+1].tag+segtree[now*2+1].val?getval(now*2+1,l,mid,p,tp):getval(now*2+2,mid+1,r,p,tp);
	int re;
	if(tp == 0){
		re = 0;
		if(segtree[now*2+1].tag+segtree[now*2+1].val != 0)re = getval(now*2+1,l,mid,p,tp);
		if(mid<p&&segtree[now*2+2].val+segtree[now*2+2].tag != 0)re = max(re,getval(now*2+2,mid+1,r,p,tp));
		return re;
	}
	else{
		re = inf;
		if(segtree[now*2+2].val+segtree[now*2+2].tag)re = getval(now*2+2,mid+1,r,p,tp);
		if(mid>=p&&segtree[now*2+1].val+segtree[now*2+1].tag)re = min(re,getval(now*2+1,l,mid,p,tp));
		return re;
	}
}

void solve(){
	int n;
	cin>>n;
	all = {0,inf};
	for(int i = 0;i<n;i++){
		int s,e,c;
		cin>>s>>e>>c;
		req[c].push_back(make_tuple(s,e,i));
		all.push_back(s);
		all.push_back(e);
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	modify(0,0,all.size()-1,0,0,1);
	modify(0,0,all.size()-1,all.size()-1,all.size()-1,1);
	for(int i = 1;i<=n;i++){
		for(auto &j:req[i]){
			get<0>(j) = lower_bound(_all(all),get<0>(j))-all.begin();
			get<1>(j) = lower_bound(_all(all),get<1>(j))-all.begin();
			modify(0,0,all.size()-1,get<0>(j),get<1>(j),1);
		}
	}
	for(int i = 1;i<=n;i++){
		for(auto &j:req[i]){
			modify(0,0,all.size()-1,get<0>(j),get<1>(j),-1);
		}
		for(auto &j:req[i]){
			int l = get<0>(j),r = get<1>(j),id = get<2>(j);
			int rpos = getval(0,0,all.size()-1,get<0>(j),1),lpos = getval(0,0,all.size()-1,get<1>(j),0);
			ans[id] = inf;
			if(lpos != 0)ans[id] = min(ans[id],all[l]-lpos);
			if(rpos != inf)ans[id] = min(ans[id],rpos-all[r]);
			ans[id] = max(ans[id],0);
			//cout<<id<<":"<<lpos<<','<<rpos<<'\n';
		}
		for(auto &j:req[i]){
			modify(0,0,all.size()-1,get<0>(j),get<1>(j),1);
		}
	}
	for(int i = 0;i<all.size()*4;i++)segtree[i].val =segtree[i].tag = 0;
	for(int i = 0;i<n;i++)cout<<ans[i]<<' ';cout<<'\n';
	for(int i = 1;i<=n;i++)req[i].clear();
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
