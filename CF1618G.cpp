#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 4e5+10;
const int inf = 1e9;
int n,m,q;
ll tsum = 0;
pll arr[mxn];
ll ans[mxn];
vector<pii> req;
vector<int> trash;

struct node{
	int pl,pr,cnt;
	ll sum;
	node(){
		pl = pr = cnt = sum = 0;
	}
};
node segtree[mxn*40];
int newnode(){
	int tmp = trash.back();
	trash.pop_back();
	segtree[tmp].pl = segtree[tmp].pr = segtree[tmp].cnt = segtree[tmp].sum = 0;
	return tmp;
}

int modify(int now,int l,int r,int p){
	if(!now)now = newnode();
	if(l == r){
		segtree[now].cnt++;
		segtree[now].sum += p;
		return now;
	}
	int mid = (l+r)>>1;
	if(mid>=p)segtree[now].pl = modify(segtree[now].pl,l,mid,p);
	else segtree[now].pr = modify(segtree[now].pr,mid+1,r,p);
	int ls = segtree[now].pl,rs = segtree[now].pr;
	segtree[now].cnt = segtree[ls].cnt+segtree[rs].cnt;
	segtree[now].sum = segtree[ls].sum+segtree[rs].sum;
	return now;
}
void recycle(int now){
	if(!now)return;
	trash.push_back(now);
	if(segtree[now].pl)recycle(segtree[now].pl);
	if(segtree[now].pr)recycle(segtree[now].pr);
}

ll getbig(int now,int l,int r,int tar){
	if(l == r){
		return 1ll*tar*l;
	}
	int mid = (l+r)>>1;
	int ls = segtree[now].pl,rs = segtree[now].pr;
	if(segtree[rs].cnt>=tar)return getbig(rs,mid+1,r,tar);
	else return segtree[rs].sum+getbig(ls,l,mid,tar-segtree[rs].cnt);
}

int sz[mxn],dsu[mxn],tag[mxn],sr[mxn];
ll contr[mxn];
vector<int> v[mxn];
int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}
void onion(int a,int b){
	 a = root(a),b = root(b);
	 if(a == b)return;
	 if(sz[a]<sz[b])swap(a,b);
	 dsu[b] = a;
	 sz[a] += sz[b];
	 tag[a] += tag[b];
	 tsum -= contr[a]+contr[b];
	 if(v[a].size()<v[b].size()){
		 swap(sr[a],sr[b]);
		 v[a].swap(v[b]);
	 }
	 while(!v[b].empty()){
		 v[a].push_back(v[b].back());
		 modify(sr[a],0,inf,v[b].back());
		 v[b].pop_back();
	 }
	 recycle(sr[b]);
	 tsum += (contr[a] = getbig(sr[a],0,inf,tag[a]));
	 return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	trash.reserve(mxn*40);
	for(int i = 1;i<mxn*40;i++)trash.push_back(i);
	for(int i = 0;i<n;i++){
		cin>>arr[i].fs;
		arr[i].sc = 1;
	}
	for(int i = 0;i<m;i++){
		cin>>arr[i+n].fs;
		arr[i+n].sc = 0;
	}
	sort(arr,arr+n+m);
	for(int i = 0;i<n+m;i++){
		dsu[i] = i;
		sz[i] = 1;
		v[i].push_back(arr[i].fs);
		tag[i] = arr[i].sc;
		tsum += (contr[i] = arr[i].sc*arr[i].fs);
		sr[i] = modify(0,0,inf,arr[i].fs);
	}
	for(int i = 0;i<q;i++){
		int d;
		cin>>d;
		req.push_back({d,i});
	}
	sort(req.begin(),req.end());
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	for(int i = 1;i<n+m;i++){
		pq.push(make_pair(arr[i].fs-arr[i-1].fs,i-1));
	}
	for(auto &i:req){
		while(!pq.empty()&&pq.top().fs<=i.fs){
			onion(pq.top().sc,pq.top().sc+1);
			pq.pop();
		}
		ans[i.sc] = tsum;
	}
	for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';
	return 0;
}
