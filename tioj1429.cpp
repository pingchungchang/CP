#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<int> tree[mxn];
ll cost[mxn],lead[mxn];
int root[mxn];
vector<int> vals[mxn];
vector<int> all;
ll n,m;
ll ans = 0;

struct node{
	int pl,pr;
	ll sum,cnt;
	node(){
		pl = pr = sum = cnt = 0;
	}
};

node segtree[mxn*80];
int ppp = 0;

int newnode(){
	ppp++;
	if(ppp>=mxn*80)exit(0);
	segtree[ppp].pl = segtree[ppp].pr = segtree[ppp].sum = segtree[ppp].cnt = 0;
	return ppp;
}

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now].sum += all[p]*v;
		segtree[now].cnt += v;
		return;
	}
	int mid = (l+r)>>1;
	segtree[now].sum = segtree[now].cnt = 0;
	if(mid>=p){
		if(!segtree[now].pl)segtree[now].pl = newnode();
		modify(segtree[now].pl,l,mid,p,v);
	}
	else{
		if(!segtree[now].pr)segtree[now].pr = newnode();
		modify(segtree[now].pr,mid+1,r,p,v);
	}
	int ls = segtree[now].pl,rs = segtree[now].pr;
	if(ls)segtree[now].sum += segtree[ls].sum,segtree[now].cnt += segtree[ls].cnt;
	if(rs)segtree[now].sum += segtree[rs].sum,segtree[now].cnt += segtree[rs].cnt;
	return;
}

int getval(int now,int l,int r,ll tar){
	if(!now)return 0;
	//cout<<l<<' '<<r<<":"<<segtree[now].sum<<' '<<segtree[now].cnt<<' '<<tar<<endl;
	if(l == r){
		return min(tar/all[l],segtree[now].cnt);
	}
	int mid = (l+r)>>1;
	int ls = segtree[now].pl,rs = segtree[now].pr;
	if(ls&&segtree[ls].sum>tar)return getval(ls,l,mid,tar);
	else return getval(rs,mid+1,r,tar-segtree[ls].sum)+segtree[ls].cnt;
}

void dfs(int now){
	for(auto nxt:tree[now]){
		dfs(nxt);
		if(vals[nxt].size()>vals[now].size()){
			swap(vals[nxt],vals[now]);
			swap(root[now],root[nxt]);
		}
		while(!vals[nxt].empty()){
			modify(root[now],0,n,vals[nxt].back(),1);
			vals[now].push_back(vals[nxt].back());
			vals[nxt].pop_back();
		}
	}
	vals[now].push_back(cost[now]);
	modify(root[now],0,n,cost[now],1);
	ll tmp = getval(root[now],0,n,m);
	//cout<<now<<":"<<tmp<<endl;
	ans = max(ans,lead[now]*tmp);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int r = 0;
	for(int i = 1;i<=n;i++){
		int p;
		cin>>p>>cost[i]>>lead[i];
		if(!p)r = i;
		all.push_back(cost[i]);
		if(p)tree[p].push_back(i);
		root[i] = newnode();
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 1;i<=n;i++){
		cost[i] = lower_bound(all.begin(),all.end(),cost[i])-all.begin();
	}
	dfs(r);
	cout<<ans;
}
