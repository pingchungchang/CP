#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define mid ((l+r)>>1)

struct Q{
	int x,y,val;
	Q(){}
	const bool operator<(const Q &b)const{
		return x<b.x;
	}
};

struct node{
	ll mn,cnt,tag;
	node(){
		mn = 1e9,cnt = 0,tag = 0;
	}
};

const int mxn = 3e5+10;
node segtree[mxn*4];
int n,m;
vector<Q> req,op;
ll ans[mxn];

node pull(node pl,node pr,int tg = 0){
	node re;
	re.tag = tg;
	if(pl.tag + pl.mn > pr.tag+pr.mn){
		re.mn = pr.tag+pr.mn;
		re.cnt = pr.cnt;
	}
	else if(pr.tag+pr.mn>pl.tag+pl.mn){
		re.mn = pl.tag+pl.mn;
		re.cnt = pl.cnt;
	}
	else{
		re.mn = pl.tag+pl.mn;
		re.cnt = pl.cnt+pr.cnt;
	}
	return re;
}

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].tag += v;
		return;
	}
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	ll tmp = segtree[now].tag;
	segtree[now] = pull(segtree[now*2+1],segtree[now*2+2],segtree[now].tag);
	return;
}

node getval(int now,int l,int r,int s,int e){
	if(e<s)return node();
	node re;
	if(l>=s&&e>=r)return segtree[now];
	if(mid>=e)return pull(getval(now*2+1,l,mid,s,e),node(),segtree[now].tag);
	else if(mid<s)return pull(getval(now*2+2,mid+1,r,s,e),node(),segtree[now].tag);
	else return pull(getval(now*2+1,l,mid,s,e),getval(now*2+2,mid+1,r,s,e),segtree[now].tag);
}

void build(int now,int l,int r){
	segtree[now].cnt = r-l+1;
	segtree[now].mn = segtree[now].tag = 0;
	if(l == r)return;
	build(now*2+1,l,mid);
	build(now*2+2,mid+1,r);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=m;i++){
		int t;
		cin>>t;
		Q tmp;
		if(t == 2){
			cin>>tmp.x;
			tmp.y = i;
			tmp.val = req.size();
			req.push_back(tmp);
		}
		else{
			int l,r,x;
			cin>>l>>r>>x;
			tmp.x = l;
			tmp.y = i;
			tmp.val = x;
			op.push_back(tmp);
			tmp.x = r+1;
			tmp.val = -x;
			op.push_back(tmp);
		}
	}
	build(0,1,m);
	/*
	modify(0,1,m,1,5,1);
	modify(0,1,m,1,5,-1);
	auto tt = getval(0,1,m,1,m);
	cout<<tt.mn<<' '<<tt.tag<<' '<<tt.cnt<<endl;return 0;
   */
	sort(op.rbegin(),op.rend());
	sort(req.begin(),req.end());
	for(auto &i:req){
		while(!op.empty()&&op.back().x<=i.x){
			auto tmp = op.back();
			op.pop_back();
			modify(0,1,m,tmp.y,m,tmp.val);
		}
		node tmp = getval(0,1,m,1,i.y-1);
		if(tmp.tag+tmp.mn == 0)ans[i.val] = tmp.cnt;
	}
	for(int i = 0;i<req.size();i++)cout<<ans[i]<<'\n';
	return 0;
}
